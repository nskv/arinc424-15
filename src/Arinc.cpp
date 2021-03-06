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

#include "Arinc.h"

#include <stdio.h>
#include <string.h>

const char *
Arinc::subsectionName( Subsection ss ) // static
{
	static const char * names[] = {
		"Неизвестно",
		"Координатная сетка для минимальных высот вне маршрута (MORA)",	// AS
		"Навигационное средство ОВЧ",	// D
		"Навигационное средство ОПРС",	// DB
		"Промежуточный пункт маршрута (ППМ)",	// EA
		"Маркерный маяк",				// EM
		"Схема полёта в зоне ожидания",	// EP
		"Воздушная трасса",				// ER
		"Ограничение на авиатрассе",	// EU
		"Средство связи на трассе",		// EV
		"Контрольная точка аэродрома",	// PA
		"Район входа аэродрома",		// PB
		"Точка маршрута в районе аэродрома",	// PC
		"Стандартная схемы вылета по приборам (ВЫХОД)",	// PD
		"Стандартная схема захода на посадку (ВХОД)",	// PE
		"Схема захода на посадку",		// PF
		"Взлётно-посадочная полоса (ВПП)",	//PG
		"Курсовой или глиссадный радиомаяк",	// PI
		"Микроволновая система посадки",	// PL
		"Курсовой маркерный маяк",		// PM
		"ОПРС аэроузла",				// PN
		"Минимальная безопасная абсолютная высота (MSA)",	// PS
		"Средство связи аэродрома",		// PV
		"Маршрут авиакомпании",			// R
		"Контролируемое воздушное пространство",	// UC
		"Ограниченное воздушное пространство"		// UR
		"ФИР/УИР",						// UF
		"Крейсерский эшелон",			// TC
		"Географические координаты",	// TG
		"Контрольная точка вертодрома",	// HA
		"Средство связи вертодрома",	// HV
		"Предпочтительный маршрут",		// ET
		"Препятствия на маршруте"		// EO
	};

	if ( ss > EO )
		return 0;
	else
		return names[ ss - Unknown ];
}

const char *
Arinc::subsectionAbbr( Subsection ss )
{
	static const char * abbr[] = {
		"Unknown",
		"AS",
		"D ",
		"DB",
		"EA",
		"EM",
		"EP",
		"ER",
		"EU",
		"EV",
		"PA",
		"PB",
		"PC",
		"PD",
		"PE",
		"PF",
		"PG",
		"PI",
		"PL",
		"PM",
		"PS",
		"PV",
		"PN",
		"R ",
		"UC",
		"UR",
		"UF",
		"TC",
		"TG",
		"HA",
		"HV",
		"ET",
		"EO"
	};

	if ( ss > EO )
		return 0;
	else
		return abbr[ ss - Unknown ];
}

const char *
Arinc::fieldName( Field field )
{
	static const char * names[] = {
		0,					// Undefined

		"address",			// Address
		"airport",			// Airport
		"asclass",			// AirspaceClass - класс воздушного пространства 5.215
		"astype",			// AirspaceType - тип воздушного пространства 5.213
		"altitdesc",		// AltitDescription - описание высоты
		"altitmax",			// AltitMax
		"altitmaxunit",		// AltitMaxUnit
		"altitmin",			// AltitMin
		"altitmin2",		// AltitMin2
		"altitminunit",		// AltitMinUnit
		"altittrans",		// AltitTrans
		"angle",			// Angle - вертикальный угол 5.70
		"arcbear",			// ArcBearing - пеленг дуги 5.120
		"arccoordinates",	// ArcCoordinates
		"arcdist",			// ArcDistance - длина дуги 5.119
		"arcrad",			// ArcRadius - радиус дуги или окружности
		"atc",				// Atc - Air Traffic Control (УВД) 5.81
		"bearing",			// Bearing - пеленг
		"bear1",			// Bearing1
		"bear2",			// Bearing2
		"bear3",			// Bearing3
		"bear4",			// Bearing4
		"bear5",			// Bearing5
		"bias",
		"border",			// Border - код границы 5.18
		"boundary",			// Boundary - тип линии границы 5.118
		"comm",				// Comment
		"commtype",			// CommType - тип станции связи
		"coordinates",		// Coordinates
		"courseib",			// CourseIb
		"courseob",			// CourseOb
		"crosshei",			// Threshold Crossing Height 5.67
		"crstbl",			// CruisingTable - таблица крейсерских эшелонов 5.134
		"cycle",			// Cycle
		"datum",			// Datum
		"direction",		// Direction - ограничение по направлению 5.115
		"displacement",		// Threshold Displacement Distance 5.69
		"distance",			// Distance
		"distcomm",			// DistanceCommunication - ограничение расстояния для станции 5.188
		"distdesc",			// DistanceDescription - описание расстояния 5.187
		"disttime",			// DistanceTime - расстояние или время
		"dme",				// Dme
		"dmecoordinates",	// DmeCoordinates
		"duplicate",		// Duplicate
		"encoding",
		"eu",				// EuIndicator
		"elevation",		// Elevation
		"entrep",			// EntryReport - входное донесение 5.124
		"exceed",
		"facility",			// Facility 5.93
		"firlimup",			// FirLimitUpper - верхняя граница ФИР 5.121
		"fix",				// Fix
		"fixcenter",		// FixCenter - центральная контрольная точка 5.144
		"frequency",		// Frequency	numeric( 6,2 )
		"frequnit",			// FrequencyUnit - диапазон частот
		"freqprd",
		"gscoordinates",	// GsCoordinates - Glide Slope Coordinates - координаты глиссадного радиомаяка
		"gspos",			// GsPosition - Glide Slope Position - положение глиссадного радиомаяка
		"gt",				// GuardTransmit - приём/передача
		"h24",				// H24 - круглосуточно Y/N
		"heig1",			// Height1
		"heig2",			// Height2
		"heig3",			// Height3
		"heig4",			// Height4
		"heig5",			// Height5
		"heigunit",			// HeightUnit - единица измерения высоты 5.123
		"iata",				// Iata - код IATA
		"icao",				// Icao - код ICAO 5.14
		"ident",			// Ident
		"ident1",			// Localizer/MLS/GLS Identifier 1 5.44 5.80
		"ident2",			// Localizer/MLS/GLS Identifier 2 5.44 5.80
		"identrls",			// IdentRls - идентификатор РЛС
		"ifr",				// Ifr - instrument flight rules
		"indicator",		// Indicator
		"level",			// Level - эшелон
		"leveltrans",		// LevelTransition - эшелон перехода
		"locpos",			// Localizer Position - позиция курсового радиомаяка
		"locref",			// Localizer Reference - смещение курсового радиомаяка
		"magdev",			// MagDev		numeric( 4,1 )
		"magtrue",			// MagneticTrue индикатор
		"markertype",		// MarkerType - тип маркерного маяка 5.99
		"merit",			// Merit
		"modulation",		// Modulation - модуляция
		"mltcode",			// MultipleCode - код множественности
		"name",				// Name
		"navclass",			// NavClass
		"nearfir",			// NearFir - ближайший ФИР
		"nearuir",			// NearUir - ближайший УИР
		"notam",			// Notam
		"ord",				// Order
		"paritycheck",
		"pathterm",			// PathAndTermination
		"pubmil",			// PublicMilitary индикатор
		"radar",			// Radar
		"radlim",			// Radius Limit - максимальный радиус 5.145
		"recdnav",			// RecdNav - рекомендуемое навигационное средство
		"region",			// Region
		"rnp",				// RequestedNavPerformance - требуемая навигационная характеристика - 5.211
		"remfac",			// Remote facility
		"resttype",			// RestrictiveType - тип ограничения воздушного пространства 5.128
		"rho",				// Rho 5.25
		"rlscoordinates",	// Координаты РЛС
		"rnp",				// Required Navigation Performance
		"routetype",		// RouteType - тип маршрута
		"runway",			// Runway - идентификатор ВПП
		"rwdistance",		// RunwayDistance - наибольшая длина ВПП
		"rwgradient",		// RunwayGradient - уклон ВПП 5.212
		"secfac",			// SectorFacility - навигационное средство сектора 5.185
		"sector",			// Sectorization 5.183
		"service",			// Service - индикатор службы связи
		"sigem",			// SignalEmission - описание ВЧ сигнала
		"speed",			// Speed
		"speedlim",			// SpeedLimit - ограничение скорости
		"speedunit",		// SpeedUnit - единица измерения скорости 5.122
		"stopway",			// Концевая полоса торможения 5.79
		"theta",			// Theta 5.24
		"time",				// Time
		"timecode",			// TimeCode - временной код - 5.131
		"timeday",			// TimeDayLignt
		"timezone",			// TimeZone
		"transition",		// Transition - идентификатор перехода 5.11
		"turn",				// Turn
		"turnvalid",		// TurnDirectionValid - необходимость разворота в заданном направлении 5.22
		"uirlimup",
		"uirlimlow",
		"wpdesc",			// WaypointDescription
		"wpformat",			// WaypointFormat
		"wptype",			// WaypointType
		"wpusage",			// WaypointUsage
		"width",			// Width - ширина
		"zone",				// Zone

		"labelnumber",		// LabelNumber
		"volumenumber",		// VolumeNumber
		"arincbegin",		// ArincBegin
		"arincend"			// ArincEnd
	};

	return names[ field ];
}

Arinc::Subsection
Arinc::subsection( const char * abbr )	// static
{
	char buf[ SUBSECTION_ABBR_BUF_SIZE ];
	snprintf( buf, SUBSECTION_ABBR_BUF_SIZE, "%-2.2s", abbr );

	for ( Arinc::Subsection i = Arinc::AS; i <= Arinc::EO; ++i )
		if ( strncmp( subsectionAbbr( i ), buf, SUBSECTION_ABBR_BUF_SIZE ) == 0 )
			return i;

	return Arinc::Unknown;
}

