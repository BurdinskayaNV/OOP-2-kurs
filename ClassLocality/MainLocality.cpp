/// \file MainLocality.cpp
/// \brief тело основной программы
/// \brief Наследование - Населённый пункт
/// \brief 
/// \brief Населённый пункт - это компактно заселенная часть территории,
///        место постоянного жительства граждан, имеющая необходимые для 
///        обеспечения жизнедеятельности граждан жилые и иные здания и сооружения,
///        сооружения, собственное наименование и установленные в соответствующем
///        порядке территориальные пределы.
/// \brief 
/// \brief Город - это населённый пункт, который имеет соответствующий статус с 
///        учётом численности населения, характера занятий его жителей, 
///        географического, экономического, исторического и культурного значения.
/// \brief 
/// \brief Деревня — небольшое крестьянское селение, 
///        один из видов населённых пунктов и адресных объектов.
/// \brief 
/// \brief Город и деревню объединяет то, что там живут люди, ездит транспорт и стоят дома. 
/// \brief People_live - живут люди
/// \brief Transport - ездит транспорт
/// \brief Home - стоят дома
/// \brief walk work live - гуляют работают живут
/// \brief
/// \brief Отличие города и деревни 
/// \brief Industry - Промышленность, Agricultural - Сельское хозяйство
/// \brief Museum - Музей, Forest - Лес
/// \brief multi_house - многоэтажка, wooden_house - частный дом
/// \brief large_population - большое население, small_population - маленькое население
/// \brief
/// \brief оформлен через модуль из семи файлов
/// \brief создан репозиторий в GitHub 
/// \author Бурдинская Наталья ВМК-22
/// \date 15.12.2023

#include "Locality.h"
#include "City.h"
#include "Village.h"
#include <iostream>

int main()
{
	Locality A("Chita", "multi", 50000);
	std::cout << A.live() << std::endl;
	std::cout << A.work() << std::endl;
	std::cout << A.live(50000) << std::endl;

	City B("Borzy", "multi", 50000);
	std::cout << B.live() << std::endl;
	std::cout << B.work() << std::endl;

	Village C("Star", "small", 50000);
	std::cout << C.live() << std::endl;
	std::cout << C.work() << std::endl;
	std::cout << C.walk() << std::endl;
}
