#ifndef REVERSE_H
#define REVERSE_H

#include<memory>

#include "../pg/pg_list.h"
#include "ListNodeInterface.h"

namespace Reverse {

/*
returns pointer to string of names from the list in reversed order concatenated with '.'
Uses ListNodeInterface allowing generalisation
Important - return value has to be freed with delete[]
*/
wchar_t* reverseNames(std::unique_ptr<const ListNodeInterface> node);

/*
returns pointer to string of names from the list in reversed order concatenated with '.'
Important - return value has to be freed with delete[]
*/
wchar_t* reverseNames(const List* list);

} //namespace Reverse

#endif   /* REVERSE_H */
