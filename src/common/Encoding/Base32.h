/*
 * Copyright 2023 AzgathCore
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TRINITY_BASE32_H
#define TRINITY_BASE32_H

#include "Define.h"
#include "Optional.h"
#include <string>
#include <vector>

namespace Trinity
{
namespace Encoding
{
struct TC_COMMON_API Base32
{
    static std::string Encode(std::vector<uint8> const& data);
    static Optional<std::vector<uint8>> Decode(std::string const& data);
};
}
}

#endif
