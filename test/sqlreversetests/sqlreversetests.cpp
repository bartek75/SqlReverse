#include "gtest/gtest.h"
#include "../../libsqlreverse/reverse.h"
#include "../../libsqlreverse/PgListNode.h"

List list;

class ReverseTests : public ::testing::Test {
protected:
	virtual void SetUp() {
		Ident* tailPg = new Ident();
		tailPg->name = L"TailName";
		ListCell* tail = new ListCell();
		tail->next = NULL;
		tail->data.ptr_value = tailPg;

		Ident* headPg = new Ident();
		headPg->name = L"HeadName";
		ListCell* head = new ListCell();
		head->data.ptr_value = headPg;
		head->next = tail;

		list.length = 2;
		list.head = head;
		list.tail = tail;
	}

	virtual void TearDown() {
		delete (Ident*)list.head->data.ptr_value;
		delete list.head;
		delete (Ident*)list.tail->data.ptr_value;
		delete list.tail;
		list.length = 0;

	}
};

TEST_F(ReverseTests, Reverse)
{
	wchar_t* reversed = Reverse::reverseNames(&list);

	EXPECT_STREQ(L"TailName.HeadName", reversed);

	delete[] reversed;
}


TEST_F(ReverseTests, ReverseGeneric)
{
	std::unique_ptr<const Reverse::ListNodeInterface> listHead = std::make_unique<Reverse::PgListNode>(list_head(&list));
	wchar_t* reversed = Reverse::reverseNames(std::move(listHead));

	EXPECT_STREQ(L"TailName.HeadName", reversed);

	delete[] reversed;
}