// Copyright 2019 Kasmazyuk Nikita

#ifndef MODULES_MONEY_CONVERTER_INCLUDE_MONEY_CONVERTER_H_
#define MODULES_MONEY_CONVERTER_INCLUDE_MONEY_CONVERTER_H_

class MoneyConverter {
    double RubToDollar;
    double RubToEuro;
    double RubToShekel;
    double RubToGrivna;
    double RubToDirham;

    double DollToRub;
    double DollToEuro;
    double DollToShekel;
    double DollToGrivna;
    double DollToDirham;

    double EurToDollar;
    double EurToRub;
    double EurToShekel;
    double EurToGrivna;
    double EurToDirham;

    double ShekToRub;
    double ShekToEuro;
    double ShekToDollar;
    double ShekToGrivna;
    double ShekToDirham;

    double DirhToRub;
    double DirhToEuro;
    double DirhToShekel;
    double DirhToGrivna;
    double DirhToDollar;

    double GrivnToRub;
    double GrivnToEuro;
    double GrivnToShekel;
    double GrivnToDirham;
    double GrivnToDollar;

 public:
    double RublesToDollar(const double &Rub) {
        RubToDollar = 64.82;
        return Rub / RubToDollar;
    }
    double RublesToEuro(const double &Rub) {
        RubToEuro = 72.29;
        return Rub / RubToEuro;
    }
    double RublesToShekel(const double &Rub) {
        RubToShekel = 17.9;
        return Rub / RubToShekel;
    }
    double RublesToGrivna(const double &Rub) {
        RubToGrivna = 2.45;
        return Rub / RubToGrivna;
    }
    double RublesToDirham(const double &Rub) {
        RubToDirham = 17.65;
        return Rub / RubToDirham;
    }
    double DollarToRubles(const double &Dol) {
        DollToRub = 64.82;
        return Dol * DollToRub;
    }
    double DollarToEuro(const double &Dol) {
        DollToEuro = 0.89;
        return Dol * DollToEuro;
    }
    double DollarToGrivna(const double &Dol) {
        DollToGrivna = 26.47;
        return Dol * DollToGrivna;
    }
    double DollarToShekel(const double &Dol) {
        DollToShekel = 3.62;
        return Dol * DollToShekel;
    }
    double DollarToDirham(const double &Dol) {
        DollToDirham = 3.67;
        return Dol * DollToDirham;
    }
    double EuroToDollar(const double &Euro) {
        EurToDollar = 1.11;
        return Euro * EurToDollar;
    }
    double EuroToRubles(const double &Euro) {
        EurToRub = 72.24;
        return Euro * EurToRub;
    }
    double EuroToShekel(const double &Euro) {
        EurToShekel = 4.03;
        return Euro * EurToShekel;
    }
    double EuroToDirham(const double &Euro) {
        EurToDirham = 4.09;
        return Euro * EurToDirham;
    }
    double EuroToGrivna(const double &Euro) {
        EurToGrivna = 29.53;
        return Euro * EurToGrivna;
    }
    double ShekelToRubles(const double &Shekel) {
        ShekToRub = 17.88;
        return Shekel * ShekToRub;
    }
    double ShekelToDirham(const double &Shekel) {
        ShekToDirham = 1.01;
        return Shekel * ShekToDirham;
    }
    double ShekelToEuro(const double &Shekel) {
        ShekToEuro = 0.246;
        return Shekel * ShekToEuro;
    }
    double ShekelToDollar(const double &Shekel) {
        ShekToDollar = 0.276;
        return Shekel * ShekToDollar;
    }
    double ShekelToGrivna(const double &Shekel) {
        ShekToGrivna = 7.31;
        return Shekel * ShekToGrivna;
    }
    double DirhamToRubles(const double &Dir) {
        DirhToRub = 17.63;
        return Dir * DirhToRub;
    }
    double DirhamToEuro(const double &Dir) {
        DirhToEuro = 0.243;
        return Dir * DirhToEuro;
    }
    double DirhamToShekel(const double &Dir) {
        DirhToShekel = 0.98;
        return Dir * DirhToShekel;
    }
    double DirhamToDollar(const double &Dir) {
        DirhToDollar = 0.273;
        return Dir * DirhToDollar;
    }
    double DirhamToGrivna(const double &Dir) {
        DirhToGrivna = 7.20;
        return Dir * DirhToGrivna;
    }
    double GrivnaToRubles(const double &Grivna) {
        GrivnToRub = 2.443;
        return Grivna * GrivnToRub;
    }
    double GrivnaToEuro(const double &Grivna) {
        GrivnToEuro = 0.033;
        return Grivna * GrivnToEuro;
    }
    double GrivnaToDirham(const double &Grivna) {
        GrivnToDirham = 0.138;
        return Grivna * GrivnToDirham;
    }
    double GrivnaToShekel(const double &Grivna) {
        GrivnToShekel = 0.136;
        return Grivna * GrivnToShekel;
    }
    double GrivnaToDollar(const double &Grivna) {
        GrivnToDollar = 0.037;
        return Grivna * GrivnToDollar;
    }
};

#endif  // MODULES_MONEY_CONVERTER_INCLUDE_MONEY_CONVERTER_H_
