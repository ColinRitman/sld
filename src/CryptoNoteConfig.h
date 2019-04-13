// Copyright (c) 2011-2016 The Cryptonote developers
// Copyright (c) 2014-2017 XDN-project developers
////////////////////////////////////////////////////////////////////////////
#include "rulez.h"

#pragma once

#include <cstdint>
#include <initializer_list>
////////////////////////////////////////////////////////////////////////////

namespace CryptoNote 
{
	namespace parameters 
	{
		const uint64_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
		const std::size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
		const std::size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
		const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = ADDRESS_BASE58_PREFIX;//Prefix of the wallet address: start with 135=ZZP, 117=SLD
		const std::size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 18;
		const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 60 * 60 * 2;

		const std::size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 30;

		const uint64_t MONEY_SUPPLY                                  = static_cast<uint64_t>(-1);//Total amount of atomic units to be emitted.

		const std::size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
		const std::size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 1048576; //size of block (bytes) after which reward for block calculated using block size
		
		const std::size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 400; // 400 seems ok for Soldo
		const std::size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 8;

		const uint64_t COIN                                          = UINT64_C(100000000);// COIN - number of smallest units in one coin: 10000=ZZP, 100000000=SLD
		const uint64_t MINIMUM_FEE                                   = UINT64_C(1);// Transactions with less than this fee wouldn’t be accepted by daemons
		const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(2);//The amount bellow this value will be considered as dust: ZZP=1, SLD=2

		const uint64_t REAL_COINS_LIMITED_Z                          = UINT64_C(10000000);//Total amount of coins mineable with full reward: 10000000=SLD,10000000000=ZZP
		const uint64_t REAL_COINS_LOWSPEED_Z                         = UINT64_C(2500000);//Total amount of coins mineable with limited reward: 2500000=SLD,10000000000=ZZP
		const uint64_t MONEY_SUPPLY_MINEABLE_Z                       = REAL_COINS_LIMITED_Z*COIN;//Total amount of atomic units mineable with full reward
		const uint64_t MONEY_SUPPLY_LOWSPEED_Z                       = REAL_COINS_LOWSPEED_Z*COIN;//Total amount of atomic units mineable with limited reward
		const std::size_t   RUSH_BLOCKS_Z                                 = 1000;//Premium rewarded blocks count: ZZP=500, SLD=1000
		const uint64_t RUSH_REWARD_Z                                 = (UINT64_C(100)*COIN);//Reward for a premium block: ZZP=200000, SLD=100
		const uint64_t COMMON_REWARD_Z                               = (UINT64_C(1)*COIN);//Reward for an ordinary block: ZZP=1000, SLD=1
		const uint64_t GENESIS_BLOCK_REWARD_Z                        = (UINT64_C(50000)*COIN);//Premine amount, in atomic units: SLD=50000, ZZP=10.000.000
		const std::size_t   RUSH_REWARD_LOCK_Z                            = 750000;//Premium rewarded blocks lock time: ZZP=20000, SLD=750000

		const uint64_t DIFFICULTY_TARGET                             = 20;//Difficulty target is an ideal time period between blocks, in seconds. 20=SLD, 720=ZZP
		const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
#ifndef PASSATELLI
	//SPAGHETTI code...
		const std::size_t   DIFFICULTY_WINDOW                             = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY/12; // blocks
		const std::size_t   DIFFICULTY_CUT                                = 60;//Timestamps to cut after sorting
		const std::size_t   DIFFICULTY_LAG                                = 20;//Lag of calculating the difficulty in terms of blocks

		static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");
#endif

		const std::size_t   DIFFICULTY_FNC_VER                            = 0;//0=SLD, 2=ZZP
		const std::size_t   DIFFICULTY_ZAWY_WINDOW                        = 30;//30=SLD, 12=ZZP

		const uint64_t DEPOSIT_MIN_AMOUNT                            = 1 * COIN;
		const uint32_t DEPOSIT_MIN_TERM                              = 11000;
		const uint32_t DEPOSIT_MAX_TERM                              = 10 * 12 * 11000;
		const uint64_t DEPOSIT_MIN_TOTAL_RATE_FACTOR                 = 77000;
		const uint64_t DEPOSIT_MAX_TOTAL_RATE                        = 11;

		static_assert(DEPOSIT_MIN_TERM > 0, "Bad DEPOSIT_MIN_TERM");
		static_assert(DEPOSIT_MIN_TERM <= DEPOSIT_MAX_TERM, "Bad DEPOSIT_MAX_TERM");
		static_assert(DEPOSIT_MIN_TERM * DEPOSIT_MAX_TOTAL_RATE > DEPOSIT_MIN_TOTAL_RATE_FACTOR, "Bad DEPOSIT_MIN_TOTAL_RATE_FACTOR or DEPOSIT_MAX_TOTAL_RATE");

		const std::size_t   MAX_BLOCK_SIZE_INITIAL                        = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 4;
		const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
		const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

		const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
		const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

		const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = (60 * 60 * 4); //seconds, 4 hours
		const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = (60 * 60 * 8); //seconds, 8 hours
		const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

		const std::size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 30 / 100;
		const std::size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
		const std::size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

		const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "chain.data";
		const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "idx.data";
		const char     CRYPTONOTE_BLOCKSCACHE_FILENAME[]             = "cache.data";
		const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "mempool.data";
		const char     P2P_NET_DATA_FILENAME[]                       = "p2p.data";
		const char     CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME[]      = "chainidx.dat";
		const char     MINER_CONFIG_FILE_NAME[]                      = "common.json";
	} // parameters

	const uint64_t TIMESTAMP_HACK_1_FUTURE_TIME_LIMIT_Z				= 60 * 7;//420 seconds/21 block = SLD
	const uint64_t ACCOUNT_CREATE_TIME_ACCURACY = 60 * 60 * 24; 
	
	const uint64_t FIRST_BLOCK_TIMESTAMP_Z							= 1509321600;

	const char     CRYPTONOTE_TICKER[]                           = CRYPTONOTE_ASSET_TICKER;
	const char     CRYPTONOTE_NAME[]                             = CRYPTONOTE_ASSET_NAME;
	const char     CRYPTONOTE_APP[]                              = CRYPTONOTE_ASSET_APP;

	const char GENESIS_COINBASE_TX_HEX[] = "010101ff00002101f0c11cb027ca12cb2b52d82bbe1851432ca1aabc5362375cddfb1c9606a8d135";

	const uint32_t GENESIS_NONCE                                 = 24;
	const char     GENESIS_WALLET_Z[]                            = "LaFwtcPWr5KhN5q1t5BYjxG6HqYph1x7B49AVdeWUewC1dMrFzXMuuJBo5YHQQRqQy7wRWQnctEcDY1eRQn76APPQycHeuj";

// HISTORY OF FORKS IN ORDER OF HAPPENS ///////////////////////////////////////////////////////////////////////////////	
	const uint64_t Z_FORK_BLOCK_1									= 2;//UPGRADE_HEIGHT_V2
	const uint64_t Z_FORK_BLOCK_2									= 3;//UPGRADE_HEIGHT_V3
	const uint64_t Z_FORK_BLOCK_3									= 4;//UPGRADE_HEIGHT_V4
	const uint64_t Z_FORK_BLOCK_4									= 24000;//DIFFICULTY_ZAWY_START_BLOCK
	const uint64_t Z_FORK_BLOCK_5									= 377777;//TIMESTAMP_HACK_1_BLOCK_HEIGHT_Z
	const uint64_t Z_FORK_BLOCK_6									= 717969;// Reward reduced /*0.01/, two forks - Soldo and Goldo appeared
	const uint64_t Z_FORK_BLOCK_7									= 0;// not happend yet
	const uint64_t Z_FORK_BLOCK_8									= 0;// not happend yet
	const uint64_t Z_FORK_BLOCK_9									= 0;// not happend yet
	const uint64_t Z_FORK_BLOCK_10									= 0;// not happend yet
	const uint64_t Z_FORK_BLOCK_11									= 0;// not happend yet
	const uint64_t Z_FORK_BLOCK_12									= 0;// not happend yet
	
	//CRYPTONOTE_NETWORK is defined @ \P2p\P2pNetworks.h
	//CRYPTONOTE_NETWORK = 24d91a1b-3aa0-6ddf-3eab-e0b4fb48f9e9
	//const static boost::uuids::uuid CRYPTONOTE_NETWORK = { { 0x24, 0xD9, 0x1A, 0x1B, 0x3A, 0xA0, 0x6D, 0xDF, 0x3E, 0xAB, 0xE0, 0xB4, 0xFB, 0x48, 0xF9, 0xE9 } };

	const uint8_t  TRANSACTION_VERSION_1                         =  1;
	const uint8_t  TRANSACTION_VERSION_2                         =  2;
	
	const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
	const uint8_t  BLOCK_MAJOR_VERSION_2                         =  2;
	const uint8_t  BLOCK_MAJOR_VERSION_3                         =  3;
	const uint8_t  BLOCK_MAJOR_VERSION_4                         =  4;
	
	const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;
	const uint8_t  BLOCK_MINOR_VERSION_1                         =  1;

	const std::size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  10000;  //by default, blocks ids count in synchronizing
	const std::size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  128;    //by default, blocks count in blocks downloading
	const std::size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  1000;

	const int      P2P_DEFAULT_PORT                              = 33711;//ZZP=33721, SLD=33711
	const int      RPC_DEFAULT_PORT                              = 33712;//ZZP=33722, SLD=33712

	const std::size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  4096;
	const std::size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  1024;

	const std::size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 128 * 1024 * 1024; // 64 MB
	const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
	const std::size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 85;
	const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 300;           // seconds
	const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;      // 50000000 bytes maximum packet size
	const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 64;
	const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 10000;          // 10 seconds
	const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 10000;          // 10 seconds
	const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
	const std::size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 10000;          // 10 seconds
	const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "ab99e468743e62c86e6d07a0db4f26db5fa6c46dc2ee899b459b3a205385d460";

	const std::initializer_list<const char*> SEED_NODES = {
		"s1.soldo.in:33711",  
		"s2.soldo.in:33711",  
		"s3.soldo.in:33711",  
		"s4.soldo.in:33711",  
		"s5.soldo.in:33711",  
		"s6.soldo.in:33711",  
	};

	struct CheckpointData {
		uint32_t height;
		const char* blockId;
	};

#ifdef __GNUC__
__attribute__((unused))
#endif

	const std::initializer_list<CheckpointData> CHECKPOINTS = 
	{
		{ 10,       "9d9c8d35abe3df6d6b568ceaec0484ab4de90b117f449e3f20268d4c5157cd3c" },
		{ 500,      "6484b98d348a8bb912ccac1f57bf489e79b2e7f182fbcd85f9e6fb6cb9b75020" },
		{ 1000,     "e71a72d72446b61b70fb11bc4b9f5a9b4acbea772522876181aaab6cfeb9f8b3" },
		{ 5000,     "8c25c2783910ede539fa575edf7dbd8aae87e851081a163f51f4af381a3dc488" },
		{ 10000,    "9f5a62a04e0dea35f922c9c46240bc26d766c3cf9d45df62cc1dcb3a2b296042" },
		{ 20000,    "338b94eea1c836545b9ac52635bf56e793c4d7087327b8344f801d19d244efdc" },
		{ 24000,    "e191d6292e928410481ed6209c4d492e0f0eff82723f9a18031f85d3955dffc9" },
		{ 50000,    "d77bbc550a5e08502e8bd58e6cd5f0ec24ab00179135cd4eb99a9d7c74d8cc4e" },
		{ 75000,    "75a833470bff666bc414a5803ecd9bf1a7c19b75049ed6c4d5903690210f66fd" },
		{ 100000,   "2a9f74669832fe2e2a14129d4df423d8d2fa1547a0a24358a51fc71b810ff641" },
		{ 125000,   "776a8b2b40cf5297375b5813fde5480c6ae8525db35fad73b7b523d6d67771c8" },
		{ 150000,   "b8d953e0b5d81f8a2b0db3d3881107ec676d72e0368c88c25085a913830a6656" },
		{ 175000,   "6c8b5543f94a9fbc3914fdfd0a58277d8ff1879b1f173db6890f99425fecc3aa" },
		{ 200000,   "b529eb8efbd46d978d7ce48f18ab07bb1bf6d0e4ddb85adf9808aed781fc045b" },
		{ 225000,   "6ceb7e3443978adb2356608417bb3dd61184246979d42ad8131ab274b2138a18" },
		{ 250000,   "9269ae2275b997f5d5d34e14a40c89471cf0f5b127693cdb0ea9b4a58420d966" },
		{ 275000,   "94fb70d53ce490f44da2d15b5df8f7c498c721504c01c30e4cb6c58df26dafc7" },
		{ 300000,   "a2e254ad0064addff57808135d42ed84a42c89df93f4f3a7765d0bf0efa9b8fe" },
		{ 325000,   "a012f24b7f2a9d417a4e79a0634212aba806ec13fd78a9990e36f7339a1c0a7d" },
		{ 350000,   "aecc323b82167e13b6d0c26493af87f9b97fbbc6a5cc0e93ad46a388d0889ac0" },
		{ 377777,   "fda74af4c706dd90c3b1c229e844cb95c2f6247f412e90971355f41257599172" },
		{ 400000,   "9a7d7ac7c224ff4f9c0d7c5e8a3a749934b59747ddac04292253adb4b7f88f90" },
		{ 425000,   "a4d8679422aee196f51126bde457402b031f9abce3688980f5239b85ad515296" },
		{ 450000,   "bfb507c5057d273eb3b4a256a8e729f6e18de4b4cd4de9326de030b7cf30ad14" },
		{ 475000,   "76e9f6a822e3e3a9078132ce8b104701b1a9c55c990c4d2185631802da0b5fbe" },
		{ 500000,   "4569f0c235536786cc0d2057e1a8b9a857ed0d97e03542cc86fe4ba5756678eb" },
		{ 525000,   "eec5f77dd46dacc95ee1bf78c939bb6caef15f1a1614b5678cc288ccfbf7a7ab" },
		{ 550000,   "b920182434221a65d64726ce62bc9d9640cd7ad0e7358d1e1f8b6d02770e9813" },
		{ 575000,   "2d012a3dc3368e9083a8cdc8a21e2f4e384aaac2a6ca1fcd0bb3cf175a5d0ae8" },
		{ 600000,   "9f7306ae82b72b8c57a97a7a422825068c0187fc6f0f8aa4e067242d66f1de94" },
		{ 625000,   "465d13678c2bfe699ae4baf58a0e3c8b698b73d08cac548a6ed6df5bb38de8c2" },
		{ 650000,   "5a94c7f078099866ecaf2f8512692be48b1bff63685409e17ab1c09b3d701223" },
		{ 675000,   "c35bd4f1b8ac5f0c876855c28d463d39bea9721ca651d55f1dad32b7ac37a228" },
		{ 700000,   "f04a589aba3ab4104fd29d0aa1429e5e28ae25c63f90b7eefc489433dd6c6a6b" },
		{ 717969,   "a13f7f9871c7ed4d178e4aecbd64436ecb4bd888470034a508fee791907a6f79" },
		{ 725000,   "5e3f2475e31ec7d3eff5eb6e3d2b55755d5f3a9181f0631cf2d59d2fee8b31c8" },
		{ 740622,   "db434659e95bad3b00968bb0e16852bbbc59d0e208c0e2865d2f37e424c4530c" },
		{ 750000,   "37bdfddc9d0af0d672580e32d5ac1d95f23c107632c28f5639f0a5075d9ecb29" },
		{ 775000,   "71a6b61b287eb4aab81171490c94844ca5caa5fb480618156f3df0041877e7bb" },
		{ 800000,   "2fb0f7b23a734ab49e7ef4b34d8120a45f3f2b91a2626239234cbed4c626452f" },
		{ 825000,   "3d161f569521a7c636b892aff1ec2658a621bd129da515a2fec6fea932ef5643" },
		{ 850000,   "f85cfb4557d98974f14af9911f47450616bda1473e03c5858c592f2030e0958a" },
		{ 875000,   "74c5a04aca754591fb335d407282c0354bb1d7f9fa4dea00b391a24b9f427d58" },
		{ 900000,   "fe97d845062fd573ab594cf238c2bf710a12319bce2ddebeb121d77fb92f3888" },
		{ 925000,   "fee59465c8103864d81658e017ce0280fe9c767426a56ae56a62bf1bd4c68fba" },
		{ 950000,   "5d3bed7acfa0f47dfe1b0f47327220cc83cb7ddd6dd12dcbfaf4d391b89c85b7" },
		{ 975000,   "545b866348181ee7f8a9c3bf595ec56d5ae108019414e89bd7a9750c123a64c6" },
		{ 1000000,   "c16e8f57e815f37b2c6783616dfe5a26124578e250b7b90f4266ea724221108b" },
		{ 1025000,   "f74adf9f8d13eb17c92f697106076fe7edc40a334853ac319bfb6cab08aa0128" },
		{ 1050000,   "5b9829a212b2986a1d0a081ee6d3edee9d5a2612e4f072c21525819411822bdf" },
		{ 1075000,   "4046dd6a6782ebfbb6709e310df5a81f0d742a8f1d36acabd9d8656cb9e41229" },
		{ 1100000,   "d821cd83c4d76c96e1fd14141dc5df09765b692cf0f08e3cdcbe07bbb533f411" },
		{ 1111111,   "731410166ee9307adf693e4172c27ce3102a6fe330368549553731167ef089e4" },
		{ 1125000,   "8eb3000afed0ac949a7dacd16ced9435c953d737ef0e948e389f8da56907a388" },
		{ 1150000,   "154a414045d40b718fb163745397b9df93d9c552b9180e282a139d76f2d13b0a" },
		{ 1175000,   "fd6185a205a69d538f6fb0bb1b4e100ae45cdb4937a44ffd6a5d0c31b86235c1" },
		{ 1200000,   "aa06337eb359ec58172a33931e6be59b22aaceeaf16e67e9cf0f9f914c89cfb7" },
		{ 1225000,   "47cae233b46560f27c6f9a32be630e770dcf41abc5d521aedc01f8764bba14c4" },
		{ 1250000,   "171f1abd5dc48935d1b8a9b3f6a1e68f8977a7debe22d7db0d92d534614597f9" },
		{ 1275000,   "75ab22e2130aee49440f63f31f2e3eb5a7323072d5f0228caf3d4dec4dfcd606" },
		{ 1300000,   "ba599fd1c2f37dfbfb4cb67e9ab4930809af07301acc04fdcf0f3cc114a0deb5" },
		{ 1350000,   "39ce3e2cb03668b52f64cbf7e0cb69211b268ecb65e66d4b6d01ea97358f3286" },
		{ 1400000,   "7d0c53b36e6d7c59775f7845831d5e395b3c60bcb56048f05ffda7c239bc39d7" },
		{ 1450000,   "c7d5f263b8150fbd39752a4d3fd828cef73e3050cc07c60a82733f0380ba35fd" },
		{ 1500000,   "0c1b752a4348a4765512f7212907e9ff2a954bd4319384b32d18784985eacd40" },
		{ 1550000,   "5dd6ec4260b84aff861be863a406ef888e73909c2ceeb6a41599084aa1e4eef4" },
		{ 1600000,   "4795871ac6bf532c51dd0a926eca74c955a6ce92d29c29c398a5b7ed112354c0" },
		{ 1650000,   "557858bf30fc4dfe0f8b3f2ff73af50d58681e9b7223da20307cc59104569a58" },
		{ 1700000,   "30a34beb9792957e28eec0edb2e88ac2a954234812ded5629dcee7741c6eb307" },
		{ 1800000,   "3f20d85f6f6d411df6c12fb91cf10e2e293e57f84598a538e51fdf0bef1d9938" },
		{ 1900000,   "91985628883304ca2777d515424cb15c4e45848293294b8edda41b2d3fafc840" },
		{ 2000000,   "db0ead0f8e5663581bf58274fbb53b47b8f0022797cf6c4a4d16d823f867a9cb" },		
		{ 2100000,   "dbcf59b83513208f7bf2ba21474db7bbbbdadc2c6d0247e36a7bd2d44e020d73" },		
		{ 2200000,   "df5e5b72e32289844d49b51051979747dabd72434821ea8ff4bc661afe2fc868" },		
		{ 2222222,   "ae10829f494d65a2833d6691bb623bd5b33295dcee1d8507f70ffa4b183f09ee" },		

		{ 2228085,   "2192e5c39c0847c4e20867dd80670876f42105c9788793388bb30d03835318e8" },		
		{ 2228100,   "57233ed4996b183b45dff321a5d624f5afcf6447c8639ccfd431e914f7a710b3" },		
		{ 2228125,   "38ec595e80626a6e1989ade4476cce8e6422461c197857e0be22aaabc327a6b0" },		
		{ 2228150,   "bd741d2b8c67ba49240ea14cef25e9343d2658e1df4f15b02a8696eb789e667d" },		
		{ 2228175,   "ecb6037d8747ba1f40d5214a23fbc9b6e46970c7748c8cc632919a1e95a40cca" },		
		{ 2228200,   "6cd58918d901f40cfaa1514550c511124d9e0489cb269472e32c7fee04374e06" },		
		{ 2228225,   "e98c8d537befefb746922086213f3d877ff347267370f402149727aaf90865bf" },		
		{ 2228250,   "78ce713bcfd839312e0cc3ed72b534a03a50015cf0a3db25a9b6196a0c739f98" },		
		{ 2228275,   "89a3940df9cc4b338d53126a809cb643ac8ba9ac47dbd340b51752428d114c6a" },		
		{ 2228300,   "b4c2c49ffff9158d437aed5269f1fac8c415253d7c3387a3a6a005ffc703b778" },			
		
		{ 2244777,   "f484503e702a3ff8a5054a3ab2f32655327425ad2929bcb0328224a75705beaf" },		
		{ 2253666,   "5916fda38f4b88988961bad743cd80abc4120e518f8e8a18a03104c74ae2b5f2" },		
		{ 2257777,   "f01e8914fbcee5d5ad518a31f0dc4cb6715cbe161f6582bfce783b650c2ba76e" },		
		{ 2268050,   "75780f6fe42b8c5264319144bbc3822d2faab605a91995584ab818089dda90f6" },		
		{ 2268700,   "1845a4df7bff53dcf43d30f4a8bbee1c5eba855a5a95d52d62a97fc84b9b5e3b" },		
		{ 2289200,   "7c12db5dbdbca4f81c381188dbbbe7c9ff6c11342841516d11c417721919f5b2" },		
		{ 2293640,   "eb54329dac6b6a2b670c45519c1a81a86d0ac704326332f2d5121adacca0830e" },		
		{ 2300000,   "0933b4b03773787970dfa536faf99844f9df4f4dd0b2565af58745864d9527c1" },		
		{ 2313631,   "f3f7fe75797ccef0e955ec381cd53859d15e7f2c848b98d80f23344974b70eb4" },		
	};

} // CryptoNote

#define ALLOW_DEBUG_COMMANDS
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
