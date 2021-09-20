/* Copyright 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_CHROMIUM_SRC_CHROME_BROWSER_SERVICE_SANDBOX_TYPE_H_
#define BRAVE_CHROMIUM_SRC_CHROME_BROWSER_SERVICE_SANDBOX_TYPE_H_

#include "../../../../chrome/browser/service_sandbox_type.h"

// brave::mojom::ProfileImport
namespace brave {
namespace mojom {
class ProfileImport;
}
}  // namespace brave

template <>
inline content::SandboxType
content::GetServiceSandboxType<brave::mojom::ProfileImport>() {
  return content::SandboxType::kNoSandbox;
}

#endif  // BRAVE_CHROMIUM_SRC_CHROME_BROWSER_SERVICE_SANDBOX_TYPE_H_
