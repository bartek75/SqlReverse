#include "PgListNode.h"

namespace Reverse {

size_t PgListNode::getNameLength() const
{
	return nameLength_;
}

const wchar_t* PgListNode::getName() const
{
	return name_;
}

std::unique_ptr<const ListNodeInterface> PgListNode::getNext() const
{
	return std::make_unique<PgListNode>(node_->next);
}

bool PgListNode::hasNext() const
{
	return node_->next;
}

} //namespace Reverse