#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"


#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10


/** \brief  Increments the number of elements in ArrayList in AL_INCREMENT elements
 *
 * \param this ArrayList* Pointer to ArrayList
 *
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                    ( 0) if Ok
 *
 */
static int resizeUp(ArrayList* this);


/** \brief  Expands an ArrayList
 *
 * \param this ArrayList* Pointer to ArrayList
 * \param index int Index of the element
 *
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                    ( 0) if Ok
 *
 */
static int expand(ArrayList* this, int index);


/** \brief  Contracts an ArrayList
 *
 * \param this ArrayList* Pointer to ArrayList
 * \param index int Index of the element
 *
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                    ( 0) if Ok
 *
 */
static int contract(ArrayList* this, int index);


ArrayList* al_newArrayList(void)
{
    ArrayList* this = NULL;
    void** pElements = NULL;

    this = (ArrayList*) malloc(sizeof(ArrayList));

    if(this != NULL)
    {
        pElements = (void**) malloc(sizeof(void*) * AL_INITIAL_VALUE);

        if(pElements != NULL)
        {
            this->pElements = pElements;
            this->size = 0;
            this->reservedSize = AL_INITIAL_VALUE;

            this->add = al_add;
            this->len = al_len;
            this->contains = al_contains;
            this->set = al_set;
            this->remove = al_remove;
            this->clear = al_clear;
            this->push = al_push;
            this->indexOf = al_indexOf;
            this->isEmpty = al_isEmpty;
            this->get = al_get;
            this->pop = al_pop;
            this->containsAll = al_containsAll;
            this->sort = al_sort;
            this->clone = al_clone;
            this->subList = al_subList;
            this->deleteArrayList = al_deleteArrayList;
        }

        else
        {
            free(this);
            this = NULL;
        }
    }

    return this;
}

int al_add(ArrayList* this, void* pElement)
{
    int auxReturn = -1;
    int length;

    if(this != NULL && pElement != NULL)
    {
        length = this->len(this);

        if((length < this->reservedSize || !resizeUp(this)) && !this->set(this, length, pElement))
        {
            this->size++;
            auxReturn = 0;
        }
    }

    return auxReturn;
}

int al_deleteArrayList(ArrayList* this)
{
    int auxReturn = -1;

    if(this != NULL && !this->clear(this))
    {
        free(this->pElements);
        free(this);

        auxReturn = 0;
    }

    return auxReturn;
}

int al_len(ArrayList* this)
{
    int auxReturn = -1;

    if(this != NULL)
    {
        auxReturn = this->size;
    }

    return auxReturn;
}

void* al_get(ArrayList* this, int index)
{
    void* auxReturn = NULL;

    if(this != NULL && index >= 0 && index < this->len(this))
    {
        auxReturn = *(this->pElements + index);
    }

    return auxReturn;
}

int al_contains(ArrayList* this, void* pElement)
{
    int auxReturn = -1;

    if(this != NULL && pElement != NULL)
    {
        auxReturn = 0;

        if(this->indexOf(this, pElement) >= 0)
        {
            auxReturn = 1;
        }
    }

    return auxReturn;
}

int al_set(ArrayList* this, int index, void* pElement)
{
    int auxReturn = -1;

    if(this != NULL && index >= 0 && index <= this->len(this) && pElement != NULL)
    {
        *(this->pElements + index) = pElement;

        auxReturn = 0;
    }

    return auxReturn;
}

int al_remove(ArrayList* this, int index)
{
    int auxReturn = -1;
    int length;

    if(this != NULL && index >= 0)
    {
        length = this->len(this);

        if(index < length && (index == length - 1 || !contract(this, index)))
        {
            this->size--;
            auxReturn = 0;
        }
    }

    return auxReturn;
}

int al_clear(ArrayList* this)
{
    int auxReturn = -1;
    int i;

    if(this != NULL)
    {
        for(i = this->len(this) - 1; i >= 0; i--)
        {
            if(this->remove(this, i))
            {
                break;
            }
        }

        if(i == -1)
        {
            this->reservedSize = AL_INITIAL_VALUE;

            auxReturn = 0;
        }
    }

    return auxReturn;
}

ArrayList* al_clone(ArrayList* this)
{
    ArrayList* auxReturn = NULL;

    if(this != NULL)
    {
        auxReturn = this->subList(this, 0, this->len(this));
    }

    return auxReturn;
}

int al_push(ArrayList* this, int index, void* pElement)
{
    int auxReturn = -1;
    int length;

    if(this != NULL && index >= 0 && pElement != NULL)
    {
        length = this->len(this);

        if(index <= length && (length < this->reservedSize || !resizeUp(this)) &&
           (index == length || !expand(this, index)) && !this->set(this, index, pElement))
        {
            this->size++;
            auxReturn = 0;
        }
    }

    return auxReturn;
}

int al_indexOf(ArrayList* this, void* pElement)
{
    int auxReturn = -1;
    int length;
    int i;

    void* pAux = NULL;

    if(this != NULL && pElement != NULL)
    {
        length = this->len(this);

        for(i = 0; i < length; i++)
        {
            pAux = this->get(this, i);

            if(pAux != NULL && pAux == pElement)
            {
                auxReturn = i;
                break;
            }
        }
    }

    return auxReturn;
}

int al_isEmpty(ArrayList* this)
{
    int auxReturn = -1;

    if(this != NULL)
    {
        auxReturn = 1;

        if(this->len(this) > 0)
        {
            auxReturn = 0;
        }
    }

    return auxReturn;
}

void* al_pop(ArrayList* this, int index)
{
    void* auxReturn = NULL;

    if(this != NULL && index >= 0 && index < this->len(this))
    {
        auxReturn = this->get(this, index);

        if(this->remove(this, index))
        {
            auxReturn = NULL;
        }
    }

    return auxReturn;
}

ArrayList* al_subList(ArrayList* this, int from, int to)
{
    ArrayList* auxReturn = NULL;

    void* pElement = NULL;
    int length;
    int i;

    if(this != NULL && from >= 0 && to > 0 && from < to)
    {
        length = this->len(this);

        if(length > 0 && from < length && to <= length)
        {
            auxReturn = al_newArrayList();

            if(auxReturn != NULL)
            {
                for(i = from; i < to; i++)
                {
                    pElement = this->get(this, i);

                    if(auxReturn->add(auxReturn, pElement))
                    {
                        auxReturn->deleteArrayList(auxReturn);
                        auxReturn = NULL;
                        break;
                    }
                }
            }
        }
    }

    return auxReturn;
}

int al_containsAll(ArrayList* this, ArrayList* this2)
{
    int auxReturn = -1;
    int length;
    int i;

    void* pElement = NULL;

    if(this != NULL && this2 != NULL)
    {
        auxReturn = 1;

        length = this2->len(this2);

        for(i = 0; i < length; i++)
        {
            pElement = this2->get(this2, i);

            if(!this->contains(this, pElement))
            {
                auxReturn = 0;
                break;
            }
        }
    }

    return auxReturn;
}

int al_sort(ArrayList* this, int (*pFunc)(void*, void*), int order)
{
    int auxReturn = -1;
    int length;
    int i;
    int flagSwap;

    void* pElement1 = NULL;
    void* pElement2 = NULL;

    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
        length = this->len(this);

        if(length > 0)
        {
            do
            {
                flagSwap = 0;

                for(i = 0; i < length - 1; i++)
                {
                    pElement1 = this->get(this, i);
                    pElement2 = this->get(this, i + 1);

                    if(pElement1 != NULL && pElement2 != NULL && pFunc(pElement1, pElement2) == order - !order)
                    {
                        this->set(this, i, pElement2);
                        this->set(this, i + 1, pElement1);

                        flagSwap = 1;
                    }
                }

                length--;

            } while(flagSwap);

            auxReturn = 0;
        }
    }

    return auxReturn;
}

static int resizeUp(ArrayList* this)
{
    int auxReturn = -1;
    void** pAux = NULL;

    if(this != NULL)
    {
        pAux = (void**) realloc(this->pElements, sizeof(void*) * (this->reservedSize + AL_INCREMENT));

        if(pAux != NULL)
        {
            this->pElements = pAux;
            this->reservedSize += AL_INCREMENT;

            auxReturn = 0;
        }
    }

    return auxReturn;
}

static int expand(ArrayList* this, int index)
{
    int auxReturn = -1;
    int length;
    int i;

    if(this != NULL && index >= 0)
    {
        length = this->len(this);

        if(index < length)
        {
            for(i = length; i > index; i--)
            {
                *(this->pElements + i) = *(this->pElements + (i - 1));
            }

            auxReturn = 0;
        }
    }

    return auxReturn;
}

static int contract(ArrayList* this, int index)
{
    int auxReturn = -1;
    int length;
    int i;

    if(this != NULL && index >= 0)
    {
        length = this->len(this);

        if(index < length - 1)
        {
            for(i = index; i < length - 1; i++)
            {
                *(this->pElements + i) = *(this->pElements + (i + 1));
            }

            auxReturn = 0;
        }
    }

    return auxReturn;
}
