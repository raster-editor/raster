#[[
   Copyright (C) 2025 Letik Kirill

   This file is part of Raster.
   Raster is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Raster is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Raster.  If not, see <http://www.gnu.org/licenses/>.
]]

cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(RASTER_VERSION_MAJOR "0")
set(RASTER_VERSION_MINOR "1")
set(RASTER_VERSION_PATCH "0")

set(RASTER_VERSION "${RASTER_VERSION_MAJOR}.${RASTER_VERSION_MINOR}.${RASTER_VERSION_PATCH}")

project(Raster VERSION ${RASTER_VERSION} LANGUAGES C CXX)

include(FetchContent)

add_subdirectory(src)