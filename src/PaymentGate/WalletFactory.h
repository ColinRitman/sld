// Copyright (c) 2011-2016 The Cryptonote developers
// Copyright (c) 2014-2017 XDN-project developers
/////////////////////////////////////////////////////////////////////////////
#pragma once

#include "IWallet.h"
#include "INode.h"
#include <System/Dispatcher.h>

#include <string>
#include <memory>
/////////////////////////////////////////////////////////////////////////////
namespace CryptoNote {
class Currency;
}

namespace PaymentService {

class WalletFactory {
public:
  static CryptoNote::IWallet* createWallet(const CryptoNote::Currency& currency, CryptoNote::INode& node, System::Dispatcher& dispatcher);
private:
  WalletFactory();
  ~WalletFactory();

  static WalletFactory factory;
};

} //namespace PaymentService
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
