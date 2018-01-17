#ifndef LIBNODEINTERFACE_H
#define LIBNODEINTERFACE_H

namespace Reverse {

/*
interface defining required methods for reversing function
*/
class ListNodeInterface
{
public:
	virtual size_t getNameLength() const = 0;
	virtual const wchar_t* getName() const = 0;
	virtual std::unique_ptr<const ListNodeInterface> getNext() const = 0;
	virtual bool hasNext() const = 0;
};


} //namespace Reverse

#endif   /* LIBNODEINTERFACE_H */
