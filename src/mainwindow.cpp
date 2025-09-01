/*
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
*/

#include "mainwindow.h"
#include <qnamespace.h>

namespace Raster {
   MainWindow::MainWindow() : QMainWindow() {
      this->m_label = new QLabel(tr("Hello, Qt!"), this);
      m_label->setAlignment(Qt::AlignCenter);
      setCentralWidget(m_label);
   }
}