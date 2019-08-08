// You must add all the code for this file.
#include <sequence1.h>
#include <cassert>
/*
 The invariant of the class is...
 1. There must be a valid current index at all times in order to modify the sequence
 2. The size of the array always has to be less than CAPACITY

 */
namespace data_structures_assignment_1{

    sequence::sequence(){
        used = 0;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void sequence::start() {
        if (used > 0){
            current_index = 0;
        }
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void sequence::insert(const data_structures_assignment_1::sequence::value_type &entry) {
        assert(size() < CAPACITY);
        if (!is_item()){
            if (used > 0){
                for (std::size_t i = used; i > current_index; i--){
                    data[i] = data[i-1];
                }
                data[current_index] = entry;
                used++;
            }
            else{
                data[0] = entry;
                current_index = 0;
                used++;
            }
        }
        else{
            for (std::size_t j = used; j > current_index; j--){
                data[j] = data[j-1];
            }
            data[current_index] = entry;
            current_index = 0;
            used++;
            }



        /*if (is_item()){
            for (std::size_t i = used; i >= current_index; i--){
                data[i] = data[i-1];
                if (i = current_index){
                    data[i] = entry;
                    used++;
                }
            }
        }

        else{
            data[0] = entry;
            current_index = 0;
            used++;
        }*/
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void sequence::advance() {
        assert(is_item());
            current_index += 1;
            if (current_index >= used){
                current_index = 30;
            }

    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void sequence::attach(const data_structures_assignment_1::sequence::value_type &entry) {
        assert(size() < CAPACITY);
        if (is_item()){
            for (std::size_t j = used; j > current_index; j--){
                   data[j] = data[j-1];
            }
            data[current_index+1] = entry;
            used++;
            current_index += 1;
        }
        else{
            data[used] = entry;
            current_index = used;
            used++;
        }
        /*if (is_item()){
            for (std::size_t j = CAPACITY-2; j > current_index; j--){
                data[j+1] = data[j];
            }
            data[current_index + 1] = entry;
            current_index += 1;
            used++;
        }
        else{
            data[used] = entry;
            current_index = used;
            used++;
        }*/
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void sequence::remove_current() {
        assert(is_item());
        if (current_index >= used){
            data[current_index] = data[used];
            current_index = 30;
            used--;
        }
        else{
            for (std::size_t k = current_index; k < used; k++){
                data[k] = data[k+1];
            }
            used--;
        }
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    bool sequence::is_item() const {
        if (current_index < used){
            return true;
        }
        else{
            return false;
        }
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    double sequence::current() const {
        assert(is_item());
        return data[current_index];
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    size_t sequence::size() const {
        return used;
    }
};