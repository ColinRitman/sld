// Copyright (c) 2018, The TurtleCoin Developers

#pragma once

#include <hdwallet/Types.h>

void syncWallet(CryptoNote::INode &node,
                std::shared_ptr<WalletInfo> &walletInfo);

void checkForNewTransactions(std::shared_ptr<WalletInfo> &walletInfo);
