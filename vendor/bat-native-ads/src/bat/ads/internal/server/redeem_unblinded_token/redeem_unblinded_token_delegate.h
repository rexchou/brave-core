/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BAT_ADS_INTERNAL_SERVER_REDEEM_UNBLINDED_TOKEN_REDEEM_UNBLINDED_TOKEN_DELEGATE_H_  // NOLINT
#define BAT_ADS_INTERNAL_SERVER_REDEEM_UNBLINDED_TOKEN_REDEEM_UNBLINDED_TOKEN_DELEGATE_H_  // NOLINT

#include "bat/ads/internal/confirmations/confirmation_info.h"

namespace ads {

class RedeemUnblindedTokenDelegate {
 public:
  RedeemUnblindedTokenDelegate() = default;

  virtual ~RedeemUnblindedTokenDelegate() = default;

  virtual void OnDidRedeemUnblindedToken(
      const ConfirmationInfo& confirmation) = 0;
  virtual void OnFailedToRedeemUnblindedToken(
      const ConfirmationInfo& confirmation) = 0;
};

}  // namespace ads

#endif  // BAT_ADS_INTERNAL_SERVER_REDEEM_UNBLINDED_TOKEN_REDEEM_UNBLINDED_TOKEN_DELEGATE_H_  // NOLINT
