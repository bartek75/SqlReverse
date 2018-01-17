#include "reverse.h"
#include "PgListNode.h"

#include <cstring>
#include <list>

namespace Reverse {

//token representing pointer to name and length of the name
typedef std::pair<const wchar_t*, std::size_t> sgl_token_t;

typedef std::list<sgl_token_t> sql_tokens_t;

wchar_t* reverseNames(std::unique_ptr<const ListNodeInterface> node)
{
	std::size_t totalLenght = 0;//length of the resulting string

	sql_tokens_t sqlTokens;//list of names and their lengths

	while (node)//traversing through input list
	{
		std::size_t nameLen = node->getNameLength();
		//add token to list
		sqlTokens.push_back(std::make_pair(node->getName(), nameLen));
		totalLenght += nameLen;
		if (node->hasNext())
		{
			node = node->getNext();
		}
		else
		{
			node = nullptr;
		}
	}

	totalLenght += sqlTokens.size();//add number of dots + terminating null
	wchar_t* ret = new wchar_t[totalLenght];

	std::size_t position = 0;
	//iterating through the list in reversed order
	for (auto rit = sqlTokens.rbegin(); rit != sqlTokens.rend(); ++rit)
	{
		auto sqlToken = *rit;
		//inserting names to resulting string
		std::memcpy(&ret[position], sqlToken.first, sqlToken.second * sizeof(wchar_t));
		position += sqlToken.second;
		ret[position++] = L'.';
	}
	ret[position - 1] = 0; //terminate the string replacing last "."

	return ret;

}

/*
returns pointer to string of names from the list in reversed order concatenated with '.'
Important - return value has to be freed with delete[]
*/
wchar_t* reverseNames(const List* list)
{
	if (!list)
	{
		return nullptr;
	}

	std::size_t totalLength = 0;//length of the resulting string

	sql_tokens_t sqlTokens;//list of names and their lengths
	const ListCell* node = list_head(list);

	while (node)//traversing through input list
	{
		Ident* value = static_cast<Ident*>(node->data.ptr_value);
		std::size_t nameLen = wcslen(value->name);
		//add token to list
		sqlTokens.push_back(std::make_pair(value->name, nameLen));
		totalLength += nameLen;
		node = node->next;
	}

	totalLength += sqlTokens.size();//add number of dots + terminating null
	wchar_t* ret = new wchar_t[totalLength];

	std::size_t position = 0;
	//iterating through the list in reversed order
	for (auto rit = sqlTokens.rbegin(); rit != sqlTokens.rend(); ++rit)
	{
		auto sqlToken = *rit;
		//inserting names to resulting string
		std::memcpy(&ret[position], sqlToken.first, sqlToken.second * sizeof(wchar_t));
		position += sqlToken.second;
		ret[position++] = L'.';
	}
	ret[position - 1] = 0; //terminate the string replacing last "."

	return ret;

}


} //namespace Reverse