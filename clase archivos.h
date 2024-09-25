
#pragma once

#include <cstring>
#include <string>
#include "gorriti.h"


class gorriti_archivo{

private:

   std::string _nombre_archivo;

public:
    gorriti_archivo();

     bool guardar_archivo(gorriti &registro);

     gorriti leer_archivo(int posicion);


     int get_cantidad_archivo();





};
