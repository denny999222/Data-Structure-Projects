// You need to write this entire file.
#include <sequence3.h>
#include <cassert>
using namespace std;

namespace data_structures_assignment3{

    sequence::sequence(){
        head_ptr = nullptr;
        tail_ptr = nullptr;
        cursor = nullptr;
        precursor = nullptr;
        amount_of_nodes = 0;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    sequence::sequence(const data_structures_assignment3::sequence &source) {
        //empty list
        if(source.amount_of_nodes == 0){
            head_ptr = nullptr;
            cursor = nullptr;
            precursor = nullptr;
            tail_ptr = nullptr;
            amount_of_nodes = 0;
        }
        //not empty
        else {
            list_clear(head_ptr);
            list_copy(source.head_ptr, head_ptr, tail_ptr);
            amount_of_nodes = source.amount_of_nodes;
            node *tempPreCursor;
            int count = 0;
            //Iterate through source until where precursor is then have a count variable count the position
            for (tempPreCursor = source.head_ptr; tempPreCursor != nullptr; tempPreCursor->link()) {
                count++;
                if (tempPreCursor->data() == source.precursor->data()) {
                    precursor = list_locate(head_ptr, count);
                    cursor = precursor->link();
                }
            }
            tail_ptr = list_locate(head_ptr, amount_of_nodes);
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    sequence::~sequence(){
        list_clear(head_ptr);
        amount_of_nodes = 0;
        cursor = nullptr;
        precursor = nullptr;
        tail_ptr = nullptr;
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void sequence::start() {
        if (amount_of_nodes == 0){
            cursor = nullptr;
            precursor = nullptr;
        }
        else {
            cursor = head_ptr;
            precursor = nullptr;
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void sequence::advance() {
        if (cursor != nullptr){
            precursor = cursor;
            cursor = cursor->link();
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    void sequence::insert(const data_structures_assignment3::sequence::value_type &entry) {
        //There is a current item
        if (is_item()){
            if(cursor == head_ptr){
                list_head_insert(head_ptr, entry);
                cursor = head_ptr;
                amount_of_nodes++;
            }
            else {
                list_insert(precursor, entry);
                cursor = precursor->link();
                amount_of_nodes++;
                tail_ptr = list_locate(head_ptr, amount_of_nodes);
            }
        }
        // no current item
        else{
            // empty list
            if (amount_of_nodes == 0){
                list_head_insert(head_ptr, entry);
                cursor = head_ptr;
                precursor = nullptr;
                amount_of_nodes++;
                tail_ptr = list_locate(head_ptr, amount_of_nodes);
            }
            //cursor is at end of list which points to nullptr but isnt empty
            else{
                node* temp_ptr = head_ptr;
                list_head_insert(head_ptr, entry);
                head_ptr->set_link(temp_ptr);
                amount_of_nodes++;
                cursor = head_ptr;
                precursor = nullptr;
            }
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void sequence::attach(const data_structures_assignment3::sequence::value_type &entry) {
        //There is a current item
        if(is_item()){
            list_insert(cursor, entry);
            precursor = cursor;
            cursor = cursor->link();
            amount_of_nodes++;
            tail_ptr = list_locate(head_ptr,amount_of_nodes);
        }
        //no current item
        else{
            //Empty list
            if(amount_of_nodes == 0){
                list_head_insert(head_ptr, entry);
                cursor = head_ptr;
                precursor = head_ptr;
                amount_of_nodes++;
                tail_ptr = list_locate(head_ptr, amount_of_nodes);
            }
            //cursor is at the end of list and is pointing to nullptr
            else{
                node* tempPtr = new node(entry);
                precursor->set_link(tempPtr);
                cursor = tempPtr;
                tail_ptr = tempPtr;
                amount_of_nodes++;
            }
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void sequence::remove_current() {
        assert(is_item());
        //cursor is the first item on sequence
        if(cursor == head_ptr){
            // only one node
            if(amount_of_nodes == 1){
                cursor = nullptr;
                precursor = nullptr;
            }
            //more than one node
            else {
                precursor = cursor;
                cursor = cursor->link();
            }
            list_head_remove(head_ptr);
            amount_of_nodes--;
        }
        //cursor is the last item on sequence
        else if(cursor == tail_ptr){
            list_remove(precursor);
            amount_of_nodes--;
            cursor = nullptr;
            tail_ptr = precursor;
        }
        //cursor is middle of sequence
        else{
            cursor = cursor->link();
            list_remove(precursor);
            amount_of_nodes--;
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void sequence::operator=(const data_structures_assignment3::sequence &source) {
        if(source.amount_of_nodes == 0){
            list_clear(head_ptr);
            cursor = nullptr;
            precursor = nullptr;
            tail_ptr = nullptr;
            amount_of_nodes = 0;
        }
        else {
            list_clear(head_ptr);
            list_copy(source.head_ptr, head_ptr, tail_ptr);
            amount_of_nodes = source.amount_of_nodes;
            cursor = source.cursor;
            precursor = source.precursor;
            tail_ptr = source.tail_ptr;
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    size_t sequence::size() const {
        return amount_of_nodes;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    bool sequence::is_item() const {
        if (cursor != nullptr){
            return true;
        }
        else{
            return false;
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    double sequence::current() const {
        return cursor->data();
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}