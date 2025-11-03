#include "funkcijos.h"

template void NuskaitymasIsFailo<std::vector<Studentas>>(std::vector<Studentas>&, std::string);
template void NuskaitymasIsFailo<std::list<Studentas>>(std::list<Studentas>&, std::string);
template void IsvedimasIFaila<std::vector<Studentas>>(std::vector<Studentas>&, std::string);
template void IsvedimasIFaila<std::list<Studentas>>(std::list<Studentas>&, std::string);
template void StudentuKategorizacija<std::vector<Studentas>>(std::vector<Studentas>&, std::vector<Studentas>&, std::vector<Studentas>&);
template void StudentuKategorizacija<std::list<Studentas>>(std::list<Studentas>&, std::list<Studentas>&, std::list<Studentas>&);
template void FailuTestavimas<std::vector<Studentas>>(std::vector<Studentas>&, std::vector<Studentas>&, std::vector<Studentas>&, std::string);
template void FailuTestavimas<std::list<Studentas>>(std::list<Studentas>&, std::list<Studentas>&, std::list<Studentas>&, std::string);
template void StudentuRusiavimas<std::vector<Studentas>>(std::vector<Studentas>&, std::string);
template void StudentuRusiavimas<std::list<Studentas>>(std::list<Studentas>&, std::string);
template void IsvedimasITerminala<std::vector<Studentas>>(std::vector<Studentas>&);
template void IsvedimasITerminala<std::list<Studentas>>(std::list<Studentas>&);