#include"page.h"

void CPage::setInPoint(int x)
{
    in_point = x;
}

int CPage::getInPoint()
{
    return in_point;
}

void CPage::setLastUsedPoint(int x)
{
    last_used_point = x;
}

int CPage::getLastUsedPoint()
{
    return last_used_point;
}

void CPage::setPageId(int x)
{
    page_id = x;
}

int CPage::getPageId()
{
    return page_id;
}



Instruction &CPage::operator[](unsigned int offset)
{
    return ins_vec[offset];
}
