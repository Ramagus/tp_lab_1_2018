/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __ARRAYLIST
#define __ARRAYLIST

struct ArrayList
{
    void** pElements;
    int size;
    int reservedSize;

    int     (*add)();
    int     (*len)();
    int     (*contains)();
    int     (*set)();
    int     (*remove)();
    int     (*clear)();
    int     (*push)();
    int     (*indexOf)();
    int     (*isEmpty)();
    void*   (*get)();
    void*   (*pop)();
    int     (*containsAll)();
    int     (*sort)();
    struct ArrayList* (* clone)();
    struct ArrayList* (*subList)();
    int     (*deleteArrayList)();

} typedef ArrayList;

#endif


/** \brief  Allocates a new ArrayList with AL_INITIAL_VALUE elements
 *
 * \param void
 *
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                           (pointer to new ArrayList) if Ok
 *
 */
ArrayList* al_newArrayList(void);


/** \brief  Adds an element to ArrayList and, if is
 *          nessesary, resizes the array
 *
 * \param this ArrayList* Pointer to ArrayList
 * \param pElement void* Pointer to element
 *
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                    ( 0) if Ok
 *
 */
int al_add(ArrayList* this, void* pElement);


/** \brief  Deletes the ArrayList
 *
 * \param this ArrayList* Pointer to ArrayList
 *
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                    ( 0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this);


/** \brief  Returns the ArrayList Size
 *
 * \param this ArrayList* Pointer to ArrayList
 *
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                    Length of array
 *
 */
int al_len(ArrayList* this);


/** \brief  Gets an element by index
 *
 * \param this ArrayList* Pointer to ArrayList
 * \param index int Index of the element
 *
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                      (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this, int index);


/** \brief  Returns true if pList contains at least one element, pElement
 *
 * \param this ArrayList* Pointer to ArrayList
 * \param pElement void* Pointer to element
 *
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                    ( 0) if Ok, but not found a element
 *                    ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement);


/** \brief  Sets an element in ArrayList at index position
 *
 * \param this ArrayList* Pointer to ArrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 *
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                    ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index, void* pElement);


/** \brief  Removes an element by index
*
 * \param this ArrayList* Pointer to ArrayList
 * \param index int Index of the element
 *
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                    ( 0) if Ok
 */
int al_remove(ArrayList* this, int index);



/** \brief  Removes all of the elements from this list
 *
 * \param this ArrayList* Pointer to ArrayList
 *
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                    ( 0) if Ok
 */
int al_clear(ArrayList* this);


/** \brief  Returns an array containing all of the elements in this list in proper sequence
 *
 * \param this ArrayList* Pointer to ArrayList
 *
 * \return ArrayList* Return (NULL) if Error [pList is NULL pointer]
 *                           (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this);


/** \brief  Inserts the element at the specified position
 *
 * \param this ArrayList* Pointer to ArrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 *
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                    ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement);


/** \brief  Returns the index of the first occurrence of the specified element
 *
 * \param this ArrayList* Pointer to ArrayList
 * \param pElement void* Pointer to element
 *
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                    (Index to element) if Ok
 *
 */
int al_indexOf(ArrayList* this, void* pElement);


/** \brief  Returns true if this list contains no elements
 *
 * \param this ArrayList* Pointer to ArrayList
 *
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                    ( 0) if is not Empty
 *                    ( 1) if is Empty
 *
 */
int al_isEmpty(ArrayList* this);


/** \brief  Removes the item at the given position in the list, and returns it
 *
 * \param this ArrayList* Pointer to ArrayList
 * \param index int Index of the element
 *
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                    (Element pointer) if Ok
 *
 */
void* al_pop(ArrayList* this, int index);


/** \brief  Returns a new ArrayList with a portion of pList between the specified
 *          fromIndex, inclusive, and toIndex, exclusive
 *
 * \param this ArrayList* Pointer to ArrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 *
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'fromIndex' or invalid 'toIndex']
 *                    (Pointer to new array) if Ok
 *
 */
ArrayList* al_subList(ArrayList* this, int from, int to);


/** \brief  Returns true if pList contains all of the elements of pList2
 *
 * \param this ArrayList* Pointer to ArrayList
 * \param this2 ArrayList* Pointer to ArrayList
 *
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                    ( 0) if not contains all
 *                    ( 1) if contains all
 *
 */
int al_containsAll(ArrayList* this, ArrayList* this2);


/** \brief  Sorts objects of list using compare pFunc
 *
 * \param this ArrayList* Pointer to ArrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of ArrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 *
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                    ( 0) if Ok
 *
 */
int al_sort(ArrayList* this, int (*pFunc)(void*, void*), int order);

