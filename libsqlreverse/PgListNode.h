#ifndef PGLISTNODE_H
#define PGLISTNODE_H

#include<memory>

#include "../pg/pg_list.h"
#include "ListNodeInterface.h"

namespace Reverse {

/*
Postgresql list node implementation 
*/
class PgListNode : public ListNodeInterface
{
public:
	PgListNode(const ListCell* node) : node_(node)
	{
		if (node)
		{
			value_ = static_cast<Ident*>(node->data.ptr_value);
			name_ = value_->name;
			nameLength_ = wcslen(name_);
		}
		else
		{
			value_ = nullptr;
			nameLength_ = 0;
			name_ = nullptr;
		}
	}


	virtual size_t getNameLength() const;

	virtual const wchar_t* getName() const;

	virtual std::unique_ptr<const ListNodeInterface> getNext() const;

	virtual bool hasNext() const;

private:
	const ListCell* node_{ nullptr };
	const Ident* value_{ nullptr };
	std::size_t nameLength_{ 0 };
	const wchar_t* name_{ nullptr };
};

} //namespace Reverse

#endif   /* PGLISTNODE_H */
