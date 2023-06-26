// Facility.cpp

#include "Facility.hpp"

Facility::Facility(std::time_t startDate, std::time_t endDate, double trancheAmount, const std::string& currency, const std::vector<std::string>& lenders)
    : startDate(startDate), endDate(endDate), trancheAmount(trancheAmount), currency(currency), lenders(lenders), interestRate(0.25), outstandingBalance(trancheAmount) {}


std::time_t Facility::getStartDate() {
    return startDate;
}

std::time_t Facility::getEndDate() {
    return endDate;
}

double Facility::getTrancheAmount() {
    return trancheAmount;
}

std::string Facility::getCurrency() {
    return currency;
}

std::vector<std::string> Facility::getLenders() {
    return lenders;
}

double Facility::getInterestRate() {
    return interestRate;
}

double Facility::getOutstandingBalance() {
    return outstandingBalance;
}

void Facility::setOutstandingBalance(double outstandingBalanceX) {
    outstandingBalance = outstandingBalanceX;
}




double Facility::getRemainingBalance() {
    // Implémentez ici le calcul du solde restant sur la facility après les remboursements
    // Retournez le montant du solde restant
    // Vous pouvez utiliser les remboursements effectués jusqu'à présent pour calculer le solde
    double totalRepayment = 0.0;
    for (Part* part : parts) {
        totalRepayment += part->getRepaymentAmount();
    }
    return trancheAmount - totalRepayment;
}



void Facility::applyPart(Part* part) {
    // Ajoutez la part à la liste des parts
    parts.push_back(part);
    
    // Ajustez le montant de la tranche en fonction de la part versée
    trancheAmount -= part->getRepaymentAmount();
    adjustInterestRate();
}



double Facility::calculateInterest() {
    // Calcul des intérêts en utilisant la formule spécifiée
    double interest_payed = (outstandingBalance * interestRate) / trancheAmount;
    double interested_payed = outstandingBalance * interest_payed;

    return interested_payed;
}

void Facility::applyPayment(double amount) {
    // Calcul des intérêts à partir du montant du paiement
    double interest_payed = (amount * interestRate) / trancheAmount;

    
    // Mise à jour du solde restant et du taux d'intérêt
    outstandingBalance -= amount;
    interestRate = (interestRate * outstandingBalance) / trancheAmount;

}

void Facility::setTrancheAmount(double amount) {
    trancheAmount = amount;
}

std::string Facility::getId() const {
    // Génération de l'identifiant unique pour la facility
    std::string id = "FAC"; // Préfixe de l'identifiant
    
    // Conversion de la date de début en une chaîne de caractères
    std::tm* startDateStruct = std::localtime(&startDate);
    char startDateStr[11]; // Tableau de caractères pour stocker la date de début
    std::strftime(startDateStr, sizeof(startDateStr), "%Y%m%d", startDateStruct);
    
    // Conversion de la date de fin en une chaîne de caractères
    std::tm* endDateStruct = std::localtime(&endDate);
    char endDateStr[11]; // Tableau de caractères pour stocker la date de fin
    std::strftime(endDateStr, sizeof(endDateStr), "%Y%m%d", endDateStruct);
    
    // Concaténation des informations pour former l'identifiant complet
    id += startDateStr + std::string("-") + endDateStr;
    
    return id;
}
void Facility::adjustInterestRate() {
    
    interestRate = (interestRate * outstandingBalance) / trancheAmount;

}

