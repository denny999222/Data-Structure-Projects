// You must provide all of this code.
#include <cassert>
#include <sequence2.h>
#include <algorithm>
using namespace std;
#include <cmath>

namespace data_structures_assignment_3{


        sequence::sequence(data_structures_assignment_3::sequence::size_type initial_capacity) {
            data = new value_type[initial_capacity];
            CAPACITY = initial_capacity;
            used = 0;
        }
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        sequence::sequence(const data_structures_assignment_3::sequence &source) {
            data = new value_type[source.CAPACITY];
            CAPACITY = source.CAPACITY;
            used = source.used;
            std::copy(source.data, source.data+used, data);
        }
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        sequence::~sequence() {
            delete [] data;
        }
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        void sequence::resize(data_structures_assignment_3::sequence::size_type new_capacity) {
            if(new_capacity >= used) {
                CAPACITY = new_capacity;
                value_type *data2;
                data2 = new value_type[CAPACITY];
                std::copy(data, data + used, data2);
                delete[] data;
                data = data2;
            }
        }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        void sequence::start() {
            if (used==0){
                current_index = CAPACITY + 1;
            }
            else{
                current_index = 0;
            }
        }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        void sequence::advance() {
            if (is_item()) {
                current_index += 1;
                if (current_index >= used) {
                    current_index = CAPACITY;
                }
            }
            /*assert(is_item());
            if (current_index == used-1){
                current_index = CAPACITY;
            }
            else{
                current_index += 1;
            }*/
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

    sequence::value_type sequence::current() const {
            assert(is_item());
            return data[current_index];
        }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    sequence::size_type sequence::size() const {
            return used;
        }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void sequence::insert(const data_structures_assignment_3::sequence::value_type &entry) {

            // CURRENT ITEM WORKS
            if (is_item()){
                // no more space
                if (used==CAPACITY){
                    resize(CAPACITY+10);
                    for (std::size_t b = used; b > current_index; b--) {
                        data[b] = data[b - 1];
                    }
                    used++;
                    data[current_index] = entry;
                }
                // enough space
                else{
                    for (std::size_t f = used; f > current_index; f--) {
                        data[f] = data[f-1];
                    }
                    used++;
                    data[current_index] = entry;
                }
            }
            // CURRENT ITEM DOESN'T WORK
            else{
                // no items yet
                if (used==0){
                    data[0] = entry;
                    used++;
                    current_index = 0;
                }
                // already items
                else{
                    // no space
                    if (used==CAPACITY){
                        resize(CAPACITY+10);
                        for (std::size_t q = used; q > 0; q--) {
                            data[q] = data[q-1];
                        }
                        used++;
                        current_index = 0;
                        data[0] = entry;
                    }
                    // there is space
                    else{
                        for (std::size_t m = used; m > 0; m--){
                            data[m] = data[m-1];
                        }
                        data[0] = entry;
                        used++;
                        current_index = 0;
                    }
                }
            }


        }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void sequence::attach(const data_structures_assignment_3::sequence::value_type &entry) {

            if (is_item()){
                // Current index AND not enough space
                if (used==CAPACITY){
                    resize(CAPACITY+10);
                    for (std::size_t h = used; h > current_index; h--){
                        data[h] = data[h-1];
                    }
                    used++;
                    current_index++;
                    data[current_index] = entry;
                }
                // Current Index with enough space
                else{
                    for (std::size_t y = used; y > current_index; y--){
                        data[y] = data[y-1];
                    }
                    used++;
                    current_index++;
                    data[current_index] = entry;
                }
            }
            else{
                // No current index AND not enough space
                if(used==CAPACITY){
                    resize(CAPACITY+10);
                    data[used] = entry;
                    used++;
                    current_index = used-1;
                }
                else if (used==0){
                    data[0] = entry;
                    used++;
                    current_index = 0;
                }
                // No current index and enough space
                else{
                    data[used] = entry;
                    used++;
                    current_index = used-1;
                }
            }

        }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void sequence::remove_current() {
        assert(is_item());
        if (current_index == used-1){
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

    void sequence::operator=(const data_structures_assignment_3::sequence &source) {
            delete []data;
            data = new value_type[source.CAPACITY];
            CAPACITY = source.CAPACITY;
            used = source.used;
            std::copy(source.data, source.data + used, data);
        }




}