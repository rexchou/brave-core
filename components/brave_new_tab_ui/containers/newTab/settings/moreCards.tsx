// Copyright (c) 2020 The Brave Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// you can obtain one at http://mozilla.org/MPL/2.0/.

import * as React from 'react'

import {
  FeaturedSettingsWidget,
  StyledBannerImage,
  StyledSettingsInfo,
  StyledSettingsTitle,
  StyledSettingsCopy,
  StyledWidgetToggle,
  SettingsWidget,
  StyledButtonIcon,
  StyledWidgetSettings,
  StyledButtonLabel
} from '../../../components/default'
import togetherBanner from './assets/bravetogether.png'
import binanceBanner from './assets/binance.png'
import rewardsBanner from './assets/braverewards.png'
import geminiBanner from './assets/gemini.png'
import HideIcon from './assets/hide-icon'
import AddIcon from '../../../components/default/addCard/assets/add-icon'

import { getLocale } from '../../../../common/locale'

interface Props {
  toggleShowBinance: () => void
  showBinance: boolean
  binanceSupported: boolean
  toggleShowTogether: () => void
  showTogether: boolean
  togetherSupported: boolean
  toggleShowRewards: () => void
  showRewards: boolean
  toggleShowGemini: () => void
  geminiSupported: boolean
  showGemini: boolean
}

class MoreCardsSettings extends React.PureComponent<Props, {}> {

  renderToggleButton = (on: boolean, toggleFunc: any, float: boolean = true) => {
    return (
      <StyledWidgetToggle
        isAdd={!on}
        float={float}
        onClick={toggleFunc}
      >
        <StyledButtonIcon>
          {
            on
            ? <HideIcon />
            : <AddIcon />
          }
        </StyledButtonIcon>
        <StyledButtonLabel>
          {
            on
            ? getLocale('hideWidget')
            : getLocale('addWidget')
          }
        </StyledButtonLabel>
      </StyledWidgetToggle>
    )
  }

  render () {
    const {
      binanceSupported,
      toggleShowBinance,
      showBinance,
      toggleShowTogether,
      showTogether,
      togetherSupported,
      toggleShowRewards,
      showRewards,
      geminiSupported,
      toggleShowGemini,
      showGemini
    } = this.props
    return (
      <StyledWidgetSettings>
        {
          togetherSupported
          ? <FeaturedSettingsWidget>
              <StyledBannerImage src={togetherBanner} />
              <StyledSettingsInfo>
                <StyledSettingsTitle>
                  {getLocale('togetherWidgetTitle')}
                </StyledSettingsTitle>
                <StyledSettingsCopy>
                  {getLocale('togetherWidgetWelcomeTitle')}
                </StyledSettingsCopy>
              </StyledSettingsInfo>
              {this.renderToggleButton(showTogether, toggleShowTogether)}
            </FeaturedSettingsWidget>
          : null
        }
        {
          geminiSupported
          ? <SettingsWidget>
              <StyledBannerImage src={geminiBanner} />
              <StyledSettingsInfo>
                <StyledSettingsTitle>
                  {'Gemini'}
                </StyledSettingsTitle>
                <StyledSettingsCopy>
                  {getLocale('geminiWidgetDesc')}
                </StyledSettingsCopy>
              </StyledSettingsInfo>
              {this.renderToggleButton(showGemini, toggleShowGemini, false)}
            </SettingsWidget>
          : null
        }
        {
          binanceSupported
          ? <SettingsWidget>
              <StyledBannerImage src={binanceBanner} />
              <StyledSettingsInfo>
                <StyledSettingsTitle>
                  {'Binance'}
                </StyledSettingsTitle>
                <StyledSettingsCopy>
                  {getLocale('binanceWidgetDesc')}
                </StyledSettingsCopy>
              </StyledSettingsInfo>
              {this.renderToggleButton(showBinance, toggleShowBinance, false)}
            </SettingsWidget>
          : null
        }
        <SettingsWidget>
          <StyledBannerImage src={rewardsBanner} />
          <StyledSettingsInfo>
            <StyledSettingsTitle>
              {getLocale('braveRewardsTitle')}
            </StyledSettingsTitle>
            <StyledSettingsCopy>
              {getLocale('rewardsWidgetDesc')}
            </StyledSettingsCopy>
          </StyledSettingsInfo>
          {this.renderToggleButton(showRewards, toggleShowRewards, false)}
        </SettingsWidget>
      </StyledWidgetSettings>
    )
  }
}

export default MoreCardsSettings
