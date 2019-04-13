// Copyright (c) 2011-2016 The Cryptonote developers
// Copyright (c) 2014-2017 XDN-project developers
///////////////////////////////////////////////////////////////////////////////
//#include "CryptoNoteConfig.h"
#include "Account.h"
#include "CryptoNoteSerialization.h"
#include "crypto/keccak.c"

namespace CryptoNote {
///////////////////////////////////////////////////////////////////////////////
AccountBase::AccountBase() {
	setNull();
}
///////////////////////////////////////////////////////////////////////////////
void AccountBase::setNull() {
	m_keys = AccountKeys();
}
///////////////////////////////////////////////////////////////////////////////
/*
void AccountBase::generate(bool _is_hdw) {
	
	Crypto::generate_keys(m_keys.address.spendPublicKey, m_keys.spendSecretKey);
  
//$$
// We derive the view secret key by taking our spend secret key, hashing
// with keccak-256, and then using this as the seed to generate a new set
// of keys - the public and private view keys. See generate_keys_from_seed
// instead of 
//	Crypto::generate_keys(m_keys.address.viewPublicKey, m_keys.viewSecretKey);

	generateViewFromSpend(m_keys.spendSecretKey, m_keys.viewSecretKey, m_keys.address.viewPublicKey);  

	m__creation_timestamp = FIRST_BLOCK_TIMESTAMP_Z;
//$$
}
*/
///////////////////////////////////////////////////////////////////////////////
void AccountBase::generateViewFromSpend(Crypto::SecretKey &spend, Crypto::SecretKey &viewSecret, Crypto::PublicKey &viewPublic) {
	
	Crypto::SecretKey viewKeySeed;

	keccak((uint8_t *)&spend, sizeof(spend), (uint8_t *)&viewKeySeed, sizeof(viewKeySeed));

	Crypto::generate_keys_from_seed(viewPublic, viewSecret, viewKeySeed);
}
///////////////////////////////////////////////////////////////////////////////
void AccountBase::generateViewFromSpend(Crypto::SecretKey &spend, Crypto::SecretKey &viewSecret) {
// If we don't need the pub key

	Crypto::PublicKey unused_dummy_variable;
	
	generateViewFromSpend(spend, viewSecret, unused_dummy_variable);
}
///////////////////////////////////////////////////////////////////////////////
const AccountKeys &AccountBase::getAccountKeys() const {
	return m_keys;
}
///////////////////////////////////////////////////////////////////////////////
void AccountBase::setAccountKeys(const AccountKeys &keys) {
	m_keys = keys;
}
///////////////////////////////////////////////////////////////////////////////
void AccountBase::serialize(ISerializer &s) {
	s(m_keys, "m_keys");
	s(m_creation_timestamp, "m_creation_timestamp");
}
///////////////////////////////////////////////////////////////////////////////
Crypto::SecretKey AccountBase::generate_or_recover(const Crypto::SecretKey& recovery_key, const Crypto::SecretKey& secondary_key, bool is_recovery, bool is_copy, bool is_deterministic)
{
    Crypto::SecretKey like_seed = 
		generate_keys_or_recover(
			m_keys.address.spendPublicKey, 
			m_keys.spendSecretKey, 
			recovery_key, 
			is_recovery);

    //rng for generating second set of keys is hash of like_seed rng
	//means only one set of electrum-style words needed for recovery
	
	// is_recovery = 0 >> Gen RND spendSecretKey ELSE use recovery_key
	// is_copy = 0 >> secondary_key=KECCAK ELSE secondary_key untouched
	// is_deterministic = 0 >> Gen RND viewSecretKey else use secondary_key
	if (!is_copy) {
		keccak((uint8_t *)&like_seed, sizeof(Crypto::SecretKey), (uint8_t *)&secondary_key, sizeof(Crypto::SecretKey));
	}
	else {
		is_deterministic = 1;
	}

    generate_keys_or_recover(
		m_keys.address.viewPublicKey, 
		m_keys.viewSecretKey, 
		secondary_key, 
		is_deterministic);
		
	
//    m_account.set_createtime(ACCOUNT_CREATE_TIME_ACCURACY);
//    m_account.set_createtime(FIRST_BLOCK_TIMESTAMP_Z);
//
//	m__creation_timestamp = time(NULL);
//	m__creation_timestamp = FIRST_BLOCK_TIMESTAMP_Z;


//ttt
	if (is_recovery) {
		m_creation_timestamp = FIRST_BLOCK_TIMESTAMP_Z;
		std::cout << "recovery mode, timestamp = " << m_creation_timestamp;
	} else {
		uint64_t now = std::time(0);
		m_creation_timestamp = now - ACCOUNT_CREATE_TIME_ACCURACY;
		std::cout << "timestamp = " << m_creation_timestamp << std::endl;
	}
	
	return like_seed;
}
///////////////////////////////////////////////////////////////////////////////
void AccountBase::create_read_only(const CryptoNote::AccountPublicAddress& address, const Crypto::SecretKey& viewkey) {

	Crypto::SecretKey zero;

    memset(&zero, 0, sizeof(zero));

	m_keys.address = address;
	m_keys.spendSecretKey = zero;
	m_keys.viewSecretKey = viewkey;
	m_creation_timestamp = FIRST_BLOCK_TIMESTAMP_Z;
}
///////////////////////////////////////////////////////////////////////////////

}
