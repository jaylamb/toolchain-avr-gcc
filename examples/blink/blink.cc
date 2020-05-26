/**
 * toolchain-avr-gcc
 *
 * Copyright 2019, 2020 Andrew Countryman <apcountryman@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not use this
 * file except in compliance with the License. You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software distributed under
 * the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

/**
 * \file
 * \brief Blink example program.
 */

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

/**
 * \brief Get the name of an I/O port's DDR register.
 *
 * \param[in] port_letter The letter identifying the I/O port.
 *
 * \return The name of the I/O port's DDR register.
 */
#define DDR_EXPAND( port_letter ) DDR##port_letter

/**
 * \brief Get the name of an I/O port's DDR register.
 *
 * \param[in] port_letter The letter identifying the I/O port.
 *
 * \return The name of the I/O port's DDR register.
 */
#define DDR( port_letter ) DDR_EXPAND( port_letter )

/**
 * \brief Get the name of an I/O port's PIN register.
 *
 * \param[in] port_letter The letter identifying the I/O port.
 *
 * \return The name of the I/O port's PIN register.
 */
#define PIN_EXPAND( port_letter ) PIN##port_letter

/**
 * \brief Get the name of an I/O port's PIN register.
 *
 * \param[in] port_letter The letter identifying the I/O port.
 *
 * \return The name of the I/O port's PIN register.
 */
#define PIN( port_letter ) PIN_EXPAND( port_letter )

namespace {

/**
 * \brief Convert a frequency, in Hz, to a period, in ms.
 *
 * \param[in] frequency_hz The frequency, in Hz, to convert.
 *
 * \return The period, in ms.
 */
constexpr double convert_frequency_hz_to_period_ms( double frequency_hz ) noexcept
{
    return 1000 / frequency_hz;
}

/**
 * \brief The DDR register for the I/O port the indicator is connected to.
 */
auto volatile & INDICATOR_DDR = DDR( INDICATOR_PORT_LETTER );

/**
 * \brief The name of the PIN register for the I/O port the indicator is connected to.
 */
auto volatile & INDICATOR_PIN = PIN( INDICATOR_PORT_LETTER );

/**
 * \brief The mask identifying the I/O port pin the indicator is connected to.
 */
constexpr auto INDICATOR_MASK = uint8_t{ 0b1 << INDICATOR_PIN_NUMBER };

/**
 * \brief The indicator blink period, in ms.
 */
constexpr auto INDICATOR_BLINK_PERIOD_MS = convert_frequency_hz_to_period_ms( INDICATOR_BLINK_FREQUENCY_HZ );

} // namespace

/**
 * \brief Blink the indicator.
 */
int main()
{
    INDICATOR_DDR = INDICATOR_MASK;

    for ( ;; ) {
        _delay_ms( INDICATOR_BLINK_PERIOD_MS / 2 );

        INDICATOR_PIN = INDICATOR_MASK;
    } // for
}
