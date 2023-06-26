#ifndef LENDERMANAGER_HPP
#define LENDERMANAGER_HPP

#include <vector>
#include "Lender.hpp"

class LenderManager {
public:
    void addLender(Lender* lender);
    void removeLender(const std::string& lenderName);
    void printLenderDetails();

private:
    std::vector<Lender*> lenders;
};

#endif
