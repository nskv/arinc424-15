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

/*! \class Arinc
 *
 * \brief 
 */

#ifndef ARINC_H
#define ARINC_H

//#include <Geo>

class ArincObjectInterface;

class Arinc
{
	private:

		/*
		\\	static
		*/


	public:
		/*! \enum Subsection
		 *
		 * \brief Подсекции ARINC
		 *
		 * Нельзя изменять !!! Многие источники данных опираются на enum Subsection
		 * как на индекс массива.
		 */
		enum Subsection {
			Unknown = 0,
			AS,		///< минимальная безопасная высота полёта вне маршрута (MORA)
			// раздел D. Навигационные средства
			D,		///< навигационные средства ОВЧ
			DB,		///< навигационные средства ОПРС
			// раздел E. Маршрут
			EA,		///< ППМ - промежуточная точка маршрута
			EM,		///< маркер авиатрассы раздела
			EP,		///< схемы полёта в зоне ожидания
			ER,		///< воздушные трассы
			EU,		///< ограничения воздушных трасс
			EV,		///< средства связи
			// раздел P. Аэродромы
			PA,		///< контрольные точки аэродромов
			PB,		///< районы входа
			PC,		///< контрольные точки аэроузла
			PD,		///< стандартная схема вылета по приборам (ВЫХОД)
			PE,		///< схемы стандартного маршрута прибытия (ВХОД)
			PF,		///< схемы захода на посадку
			PG,		///< ВПП - взлётно-посадочная полоса
			PI,		///< курсовой радиомаяк
			PL,		///< микроволновая система посадки
			PM,		///< маркеры курсового маяка
			PS,		///< минимальная высота сектора
			PV,		///< средства связи раздела
			PN,		///< ОПРС аэроузла
			// раздел R. Трассы авиакомпаний
			R,		///< трассы
			// раздел U. Ограниченное воздушное пространство
			UC,		///< контролируемое воздушное пространство
			UR,		///< ограниченное воздушное пространство
			UF,		///< ФИР/УИР
			// раздел T. Таблицы
			TC,		///< таблицы крейсерских эшелонов
			TG,		///< таблица географических координат
			HA,		///< вертодромы
			HV,		///< средство связи вертодрома
			ET,		///< предпочтительные маршруты
			EO,		///< препятствия на маршруте
			////////////////////////////////////////////////////
			/// служебные строки файла в формате Arinc424-15 ///
			////////////////////////////////////////////////////
		};

		enum Type {
			NoType,			///< Нет типа
			VolumeHeader,
			Header1,
			Header2,
			EndOfFile,
			EndOfVolume,
			Standard,		// Standard точечный объект
			StandardWay,	// Standard объект-путь
			Tailored		// должна быть последней \sa ArincLineMap::m_maps
		};

		enum Field {
			// ArincData::String
			Undefined = 0,

			Airport,		///< Код ICAO аэропорта с 2-х символьным кодом зоны
			AltitMax,		///< Максимальная высота
			AltitMin,		///< Минимальная высота
			AltitMin2,		///< Минимальная высота 2
			Bias,			///< Смещение ILS/DME
			Border,			///< Код границы (5.18)
			Comment,		///< Примечание
			Coordinates,	///< Координаты
			CourseIb,		///< Курс, заданный Магнитный Путевой Угол (МПУ) на... (inbound)
			CourseOb,		///< Курс, заданный Магнитный Путевой Угол (МПУ) от... (outbound)
			CruisingTable,	///< Таблица крейсерских жшелонов 5.134
			Cycle,			///< Цикл AIRAC в котором были последние изменения
			Datum,			///< Код исходного ориентира
			Direction,		///< Ограничение по направлению 5.115
			Distance,		///< Расстояние
			Dme,			///< Идентификотор DME
			DmeCoordinates,	///< Координаты DME
			Duplicate,		///< Идентификатор множественности маршрутов в точке (Duplicate Indicator)
			Encoding,		///< Кодировка
			EuIndicator,	///< Индикатор ограничения
			Exceed,			///< Превышение
			Fix,			///< Идентификатор ППМ
			Frequency,		///< Частота
			FreqPrd,		///< Защита частоты
			Ident,			///< Идентификатор с 2-х символьным кодом зоны
			Level,			///< Эшелон
			MagDev,			///< Магнитное склонение
			Merit,			///< Чувствительность, показатель качества (был Sens)
			Name,			///< Наименование
			NavClass,		///< Класс навигационного средства
			Order,			///< Порядок точек в многоточечном объекте
			ParityCheck,	///< Контроль чётности
			RecdNav,		///< Рекомендуемое навигационное средство
			Region,			///< Код региона (Region code)
			Rho,			///< Ро 5.25
			Rnp,			///< Требуемая навигационная характеристика (Required Navigation Performance)
			RouteType,		///< Тип маршрута
			Speed,			///< Скорость
			Theta,			///< Тэта 5.24
			Time,			///< Время
			Turn,			///< Направление разворота
			WaypointDescription,	///< Код описания ППМ
			WaypointFormat,	///< Индикатор формата имени (Name format indicator)
			WaypointType,	///< Тип ППМ
			WaypointUsage,	///< Использование ППМ на маршруте, по сути тип воздушного пространства
			Zone,			///< 3-x символьное обозначение зоны
			// ArincData::Coordinates

			// ArincData::Int
			// ArincData::Double
			// Volume Header
			LabelNumber,
			VolumeNumber,
			DataFrom,
			Tracks,
			Density
		};

		/*
		\\	static
		*/

		static const char * subsectionName( Subsection ss );

		static const char * subsectionAbbr( Subsection ss );

		static const char * fieldName( Field field );
};

#endif

