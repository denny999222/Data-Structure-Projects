sn#include <cassert>
#include "barrel.h"

namespace data_structures_assignment_1
{
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    barrel::barrel(){
        height = 1;
        water_liters = 0;
        olive_oil_liters = 0;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    barrel::barrel(double init_height, double init_water_liters, double init_olive_oil_liters) {
        assert(get_total_capacity() >= (water_liters+olive_oil_liters));
        height = init_height;
        water_liters = init_water_liters;
        olive_oil_liters = init_olive_oil_liters;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    double barrel::get_height() const {
        return height;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    double barrel::get_olive_oil_liters() const {
        return olive_oil_liters;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    double barrel::get_water_liters() const {
        return water_liters;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    double barrel::get_total_capacity() const {
        return height * 100;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    double barrel::get_empty_space() const {
        return get_total_capacity() - water_liters - olive_oil_liters;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void barrel::add_water(double liters) {
        assert(liters > 0);
        if (water_liters + olive_oil_liters + liters > get_total_capacity()){
            water_liters += liters;
            if (water_liters > get_total_capacity()){
                water_liters = get_total_capacity();
                olive_oil_liters = 0;
            }
            else {
                olive_oil_liters -= get_total_capacity() - water_liters;
            }
        }
        else{
            water_liters += liters;
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void barrel::add_olive_oil(double liters) {
        assert(liters > 0);
        if (olive_oil_liters + water_liters + liters > get_total_capacity()){
            olive_oil_liters = get_total_capacity() - water_liters;
        }
        else{
            olive_oil_liters += liters;
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void barrel::drain(double liters) {
        assert(liters > 0);
        if (liters > water_liters + olive_oil_liters){
            water_liters = 0;
            olive_oil_liters = 0;
        }
        else{
            if (liters > water_liters){
                olive_oil_liters -= liters - water_liters;
                water_liters = 0;
            }
            else{
                water_liters -= liters;
            }
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    barrel operator+(const barrel &s1, const barrel &s2){
        return barrel(s1.get_height() + s2.get_height(), s1.get_water_liters() + s2.get_water_liters(), s1.get_olive_oil_liters() + s2.get_olive_oil_liters());
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    bool operator==(const barrel &s1, const barrel &s2){
        if (s1.get_height() == s2.get_height() && s1.get_water_liters() == s2.get_water_liters() && s1.get_olive_oil_liters() == s2.get_olive_oil_liters()){
            return true;
        }
        else{
            return false;
        }
    }

};


    // Add the barrel class implementation here.

