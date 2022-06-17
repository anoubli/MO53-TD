#include "manager.h"
#include "loader.h"
#include "calculation.h"
#include "writer.h"


manager::manager()
{

}

loader manager::make_reader(std::string param){
    if (param == "bin"){
          return new bin_loader;
    }else{
        return new text_loader;
    }

}

calculation manager::make_calculation(std::string param){
    if (param == "avg"){
          return new average;
    }else{
        return new moving_average;
    }

}

writer manager::make_writer(std::string param){
    if (param == "bin"){
          return new bin_writer;
    }else{
        return new text_writer;
    }

}

storage_type manager::make_storage(std::string param){
    if (param == "list"){
          return new list_storage;
    }else{
        return new vector_storage;
    }
}





