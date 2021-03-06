/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BAT_LEDGER_LEDGER_CLIENT_H_
#define BAT_LEDGER_LEDGER_CLIENT_H_

#include <functional>
#include <memory>
#include <vector>
#include <string>
#include <map>

#include "bat/ledger/mojom_structs.h"
#include "bat/ledger/export.h"

namespace ledger {

using PublisherInfoCallback =
    std::function<void(const Result, PublisherInfoPtr)>;
// TODO(nejczdovc) we should be providing result back as well
using PublisherInfoListCallback =
    std::function<void(PublisherInfoList)>;
using FetchIconCallback = std::function<void(bool, const std::string&)>;
using LoadURLCallback = std::function<void(const ledger::UrlResponse&)>;
using OnLoadCallback = std::function<void(const Result,
                                          const std::string&)>;
using PendingContributionInfoListCallback =
    std::function<void(PendingContributionInfoList)>;
using PendingContributionsTotalCallback = std::function<void(double)>;
using GetExternalWalletsCallback =
    std::function<void(std::map<std::string, ledger::ExternalWalletPtr>)>;
using GetServerPublisherInfoCallback =
    std::function<void(ledger::ServerPublisherInfoPtr)>;
using ResultCallback = std::function<void(const Result)>;
using GetFirstContributionQueueCallback =
    std::function<void(ContributionQueuePtr)>;
using GetPromotionCallback = std::function<void(PromotionPtr)>;
using GetUnblindedTokenListCallback = std::function<void(UnblindedTokenList)>;
using GetAllPromotionsCallback = std::function<void(PromotionMap)>;

using GetTransactionReportCallback =
    std::function<void(ledger::TransactionReportInfoList)>;

using GetContributionReportCallback =
    std::function<void(ledger::ContributionReportInfoList)>;

using GetContributionInfoCallback =
    std::function<void(ContributionInfoPtr)>;

using RunDBTransactionCallback = std::function<void(DBCommandResponsePtr)>;
using GetCreateScriptCallback =
    std::function<void(const std::string&, const int)>;

using GetCredsBatchCallback = std::function<void(CredsBatchPtr)>;
using GetCredsBatchListCallback = std::function<void(CredsBatchList)>;
using GetPromotionListCallback = std::function<void(PromotionList)>;

using SKUOrderCallback =
    std::function<void(const Result, const std::string&)>;

using TransactionCallback =
    std::function<void(const Result, const std::string&)>;

using GetSKUOrderCallback = std::function<void(SKUOrderPtr)>;
using GetSKUTransactionCallback = std::function<void(SKUTransactionPtr)>;

class LEDGER_EXPORT LedgerClient {
 public:
  virtual ~LedgerClient() = default;

  virtual void OnReconcileComplete(
      const Result result,
      ContributionInfoPtr contribution) = 0;

  virtual void LoadLedgerState(OnLoadCallback callback) = 0;

  virtual void LoadPublisherState(OnLoadCallback callback) = 0;

  virtual void OnPanelPublisherInfo(
      ledger::Result result,
      ledger::PublisherInfoPtr publisher_info,
      uint64_t windowId) = 0;

  virtual void FetchFavIcon(
      const std::string& url,
      const std::string& favicon_key,
      FetchIconCallback callback) = 0;

  virtual std::string URIEncode(const std::string& value) = 0;

  virtual void LoadURL(
      const std::string& url,
      const std::vector<std::string>& headers,
      const std::string& content,
      const std::string& contentType,
      const ledger::UrlMethod method,
      ledger::LoadURLCallback callback) = 0;

  virtual void Log(
      const char* file,
      const int line,
      const int verbose_level,
      const std::string& message) = 0;

  virtual void PublisherListNormalized(ledger::PublisherInfoList list) = 0;

  virtual void SetBooleanState(const std::string& name, bool value) = 0;

  virtual bool GetBooleanState(const std::string& name) const = 0;

  virtual void SetIntegerState(const std::string& name, int value) = 0;

  virtual int GetIntegerState(const std::string& name) const = 0;

  virtual void SetDoubleState(const std::string& name, double value) = 0;

  virtual double GetDoubleState(const std::string& name) const = 0;

  virtual void SetStringState(
      const std::string& name,
      const std::string& value) = 0;

  virtual std::string GetStringState(const std::string& name) const = 0;

  virtual void SetInt64State(const std::string& name, int64_t value) = 0;

  virtual int64_t GetInt64State(const std::string& name) const = 0;

  virtual void SetUint64State(const std::string& name, uint64_t value) = 0;

  virtual uint64_t GetUint64State(const std::string& name) const = 0;

  virtual void ClearState(const std::string& name) = 0;

  virtual bool GetBooleanOption(const std::string& name) const = 0;

  virtual int GetIntegerOption(const std::string& name) const = 0;

  virtual double GetDoubleOption(const std::string& name) const = 0;

  virtual std::string GetStringOption(const std::string& name) const = 0;

  virtual int64_t GetInt64Option(const std::string& name) const = 0;

  virtual uint64_t GetUint64Option(const std::string& name) const = 0;

  virtual void OnContributeUnverifiedPublishers(
      Result result,
      const std::string& publisher_key,
      const std::string& publisher_name) = 0;

  virtual std::map<std::string, ledger::ExternalWalletPtr>
  GetExternalWallets() = 0;

  virtual void SaveExternalWallet(
      const std::string& wallet_type,
      ledger::ExternalWalletPtr wallet) = 0;

  virtual void ShowNotification(
      const std::string& type,
      const std::vector<std::string>& args,
      ledger::ResultCallback callback) = 0;

  virtual void SetTransferFee(
      const std::string& wallet_type,
      ledger::TransferFeePtr transfer_fee) = 0;

  virtual ledger::TransferFeeList GetTransferFees(
      const std::string& wallet_type) = 0;

  virtual void RemoveTransferFee(
      const std::string& wallet_type,
      const std::string& id) = 0;

  virtual ledger::ClientInfoPtr GetClientInfo() = 0;

  virtual void UnblindedTokensReady() = 0;

  virtual void ReconcileStampReset() = 0;

  virtual void RunDBTransaction(
      ledger::DBTransactionPtr transaction,
      ledger::RunDBTransactionCallback callback) = 0;

  virtual void GetCreateScript(ledger::GetCreateScriptCallback callback) = 0;

  virtual void PendingContributionSaved(const ledger::Result result) = 0;

  virtual void ClearAllNotifications() = 0;

  virtual void WalletDisconnected(const std::string& wallet_type) = 0;

  virtual void DeleteLog(ledger::ResultCallback callback) = 0;
};

}  // namespace ledger

#endif  // BAT_LEDGER_LEDGER_CLIENT_H_
