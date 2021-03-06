/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVELEDGER_ENDPOINT_PROMOTION_PUT_CAPTCHA_PUT_CAPTCHA_H_
#define BRAVELEDGER_ENDPOINT_PROMOTION_PUT_CAPTCHA_PUT_CAPTCHA_H_

#include <string>

#include "bat/ledger/ledger.h"

namespace bat_ledger {
class LedgerImpl;
}

namespace ledger {
namespace endpoint {
namespace promotion {

using PutCaptchaCallback = std::function<void(const ledger::Result result)>;

class PutCaptcha {
 public:
  explicit PutCaptcha(bat_ledger::LedgerImpl* ledger);
  ~PutCaptcha();

  void Request(
      const int x,
      const int y,
      const std::string& captcha_id,
      PutCaptchaCallback callback);

 private:
  std::string GetUrl(const std::string& captcha_id);

  std::string GeneratePayload(const int x, const int y);

  ledger::Result CheckStatusCode(const int status_code);

  void OnRequest(
      const ledger::UrlResponse& response,
      PutCaptchaCallback callback);

  bat_ledger::LedgerImpl* ledger_;  // NOT OWNED
};

}  // namespace promotion
}  // namespace endpoint
}  // namespace ledger

#endif  // BRAVELEDGER_ENDPOINT_PROMOTION_PUT_CAPTCHA_PUT_CAPTCHA_H_
