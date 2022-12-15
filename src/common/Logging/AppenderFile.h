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

#ifndef APPENDERFILE_H
#define APPENDERFILE_H

#include "Appender.h"
#include <atomic>

class TC_COMMON_API AppenderFile : public Appender
{
    public:
        static constexpr AppenderType type = APPENDER_FILE;

        AppenderFile(uint8 id, std::string const& name, LogLevel level, AppenderFlags flags, std::vector<std::string_view> const& args);
        ~AppenderFile();
        FILE* OpenFile(std::string const& name, std::string const& mode, bool backup);
        AppenderType getType() const override { return type; }

    private:
        void CloseFile();
        void _write(LogMessage const* message) override;
        FILE* logfile;
        std::string _fileName;
        std::string _logDir;
        bool _dynamicName;
        bool _backup;
        uint64 _maxFileSize;
        std::atomic<uint64> _fileSize;
};

#endif
