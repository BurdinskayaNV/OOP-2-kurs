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
/// \brief До 1000 человек – деревня, до 30 000 человек – посёлок, более 30 000 – город. 
/// \brief оформлен через модуль из семи файлов
/// \brief создан репозиторий в GitHub 
/// \author Бурдинская Наталья ВМК-22
/// \date 15.12.2023

#include "Locality.h"
#include "City.h"
#include "Village.h"

int main()
{
	Locality A("Chita", "The State Duma", 50000);
	//Locality A("Borzya", "Administration", 28000);
	cout << A.live() << endl;
	cout << A.live(28000) << endl;
	cout << A.work() << endl;
	cout << A.walk() << endl;

	City B("Borzya", 28000, "City", 10);
	cout << B.stone_houses() << endl;
	cout << B.floors() << endl;

	Village C("Newriver", 780, "Village", 1);
	cout << C.wooden_houses() << endl;
	cout << C.floors() << endl;

	A.Output();
	B.Output();
	C.Output();
}
