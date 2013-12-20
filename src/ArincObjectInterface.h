/***************************************************************************
 *   Copyright (C) 2013 by Sergey N Chursanov                              *
 *                                                                         *
 *   email: masakra@mail.ru                                                *
 *   jabber: masakra@jabber.ru                                             *
 *                                                                         *
 *   Permission is hereby granted, free of charge, to any person obtaining *
 *   a copy of this software and associated documentation files (the       *
 *   "Software"), to deal in the Software without restriction, including   *
 *   without limitation the rights to use, copy, modify, merge, publish,   *
 *   distribute, sublicense, and/or sell copies of the Software, and to    *
 *   permit persons to whom the Software is furnished to do so, subject to *
 *   the following conditions:                                             *
 *                                                                         *
 *   The above copyright notice and this permission notice shall be        *
 *   included in all copies or substantial portions of the Software.       *
 *                                                                         *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       *
 *   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    *
 *   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. *
 *   IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR     *
 *   OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, *
 *   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR *
 *   OTHER DEALINGS IN THE SOFTWARE.                                       *
 ***************************************************************************/

/*! \class ArincLineInterface
 *
 * \brief Интерфейс строки Arinc файла
 */

#ifndef ARINCOBJECTINTERFACE_H
#define ARINCOBJECTINTERFACE_H

#include <string>

#include "Arinc.h"

#include <Geo>

using namespace std;

class ArincObjectInterface
{
	public:
		virtual ~ArincObjectInterface() {};

		virtual Arinc::Subsection subsection() const = 0;

		virtual string airportIcao() const = 0;

		virtual Coordinates coordinates() const = 0;

		virtual Coordinates coordinatesDme() const = 0;

		virtual string cycle() const = 0;

		virtual string frequency() const = 0;

		virtual string ident() const = 0;

		virtual string name() const = 0;

		virtual string navClass() const = 0;

		virtual string zone() const = 0;
};

#endif

