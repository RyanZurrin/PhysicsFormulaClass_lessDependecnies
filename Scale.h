//
// Created by ryanz on 10/16/2022.
//

#ifndef PHYSICSFORMULA_SCALE_H
#define PHYSICSFORMULA_SCALE_H


/**
 * @brief Scale class that allows you to put in your weight in pounds and then
 * find what your weight would be on all the other planets in the solar system.
 */
class Scale {
public:
    /**
     * @brief Default constructor for the Scale class.
     */
    Scale();
    /**
     * @brief Constructor for the Scale class.
     * @param weight The weight of the user in pounds.
     */
    explicit Scale(double weight);

    /**
     * @brief sets the w of the user in pounds using earth's gravity as a base.
     * @param w  The w of the user in pounds.
     */
    void setWeight(double w);

    /**
     * @brief Gets the weight of the user on Mercury.
     * @return The weight of the user on Mercury.
     */
    [[nodiscard]] double getWeightOnMercury() const;

    /**
     * @brief Gets the weight of the user on Venus.
     * @return The weight of the user on Venus.
     */
    [[nodiscard]] double getWeightOnVenus() const;

    /**
     * @brief Gets the weight of the user on Earth.
     * @return The weight of the user on Earth.
     */
    [[nodiscard]] double getWeightOnEarth() const;

    /**
     * @brief Gets the weight of the user on Earth.
     * @return The weight of the user on Earth.
     */
    [[nodiscard]] double getWeightOnEarthMoon() const;

    /**
     * @brief Gets the weight of the user on Mars.
     * @return The weight of the user on Mars.
     */
    [[nodiscard]] double getWeightOnMars() const;

    /**
     * @brief Gets the weight of the user on Jupiter.
     * @return The weight of the user on Jupiter.
     */
    [[nodiscard]] double getWeightOnJupiter() const;

    /**
     * @brief Gets the weight of the user on Saturn.
     * @return The weight of the user on Saturn.
     */
    [[nodiscard]] double getWeightOnSaturn() const;

    /**
     * @brief Gets the weight of the user on Uranus.
     * @return The weight of the user on Uranus.
     */
    [[nodiscard]] double getWeightOnUranus() const;

    /**
     * @brief Gets the weight of the user on Neptune.
     * @return The weight of the user on Neptune.
     */
    [[nodiscard]] double getWeightOnNeptune() const;

    /**
     * @brief Gets the weight of the user on Pluto.
     * @return The weight of the user on Pluto.
     */
    [[nodiscard]] double getWeightOnPluto() const;

    /**
     * @brief Gets the weight of the user on the Sun.
     * @return The weight of the user on the Sun.
     */
    [[nodiscard]] double getWeightOnSun() const;

    /**
     * @brief displays all the weights of the user on all the planets in the
     * solar system.
     */
    void showAllWeights() const;

    /**
     * @brief displays the menu which allows the user to enter their weight and
     * then print thier wieght on the planet they want to see or all the planets.
     */
    void displayMenu();

    /**
     * @brief creates a run loop for the menu and program.
     */
    void run();

private:
    double weight;
    double selectedWeight;
    int selectedPlanet;
};

Scale::Scale() {
    this->weight = 0;
    this->selectedWeight = 0;
    this->selectedPlanet = 2;
}

Scale::Scale(double weight) {
    this->weight = weight;
    this->selectedWeight = 0;
    this->selectedPlanet = 2;
}

void Scale::setWeight(double w) {
    this->weight = w;
}

double Scale::getWeightOnMercury() const {
    auto weightOnMercury = this->weight * 0.38;
    return weightOnMercury;
}

double Scale::getWeightOnVenus() const {
    auto weightOnVenus = this->weight * 0.91;
    return weightOnVenus;
}

double Scale::getWeightOnEarth() const {
    return this->weight;
}

double Scale::getWeightOnEarthMoon() const {
    auto weightOnEarthMoon = this->weight * 0.17;
    return weightOnEarthMoon;
}

double Scale::getWeightOnMars() const {
    auto weightOnMars = this->weight * 0.38;
    return weightOnMars;
}

double Scale::getWeightOnJupiter() const {
    auto weightOnJupiter = this->weight * 2.34;
    return weightOnJupiter;
}

double Scale::getWeightOnSaturn() const {
    auto weightOnSaturn = this->weight * 1.06;
    return weightOnSaturn;
}

double Scale::getWeightOnUranus() const {
    auto weightOnUranus = this->weight * 0.92;
    return weightOnUranus;
}

double Scale::getWeightOnNeptune() const {
    auto weightOnNeptune = this->weight * 1.19;
    return weightOnNeptune;
}

double Scale::getWeightOnPluto() const {
    auto weightOnPluto = this->weight * 0.06;
    return weightOnPluto;
}

double Scale::getWeightOnSun() const {
    auto weightOnSun = this->weight * 27.9;
    return weightOnSun;
}

void Scale::showAllWeights() const {
    std::cout << "Weight on Mercury: " << getWeightOnMercury() << std::endl;
    std::cout << "Weight on Venus: " << getWeightOnVenus() << std::endl;
    std::cout << "Weight on Earth: " << getWeightOnEarth() << std::endl;
    std::cout << "Weight on Earth Moon: " << getWeightOnEarthMoon() << std::endl;
    std::cout << "Weight on Mars: " << getWeightOnMars() << std::endl;
    std::cout << "Weight on Jupiter: " << getWeightOnJupiter() << std::endl;
    std::cout << "Weight on Saturn: " << getWeightOnSaturn() << std::endl;
    std::cout << "Weight on Uranus: " << getWeightOnUranus() << std::endl;
    std::cout << "Weight on Neptune: " << getWeightOnNeptune() << std::endl;
    std::cout << "Weight on Pluto: " << getWeightOnPluto() << std::endl;
    std::cout << "Weight on Sun: " << getWeightOnSun() << std::endl;
}

void Scale::displayMenu() {
    vector<string> planets = {"Mercury", "Venus", "Earth", "Earth Moon", "Mars",
                              "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto",
                              "Sun"};
    std::cout << "The Solar System Weight Calculator" << std::endl;
    std::cout << "**********************************" << std::endl;
    std::cout << "1. Mercury" << std::endl;
    std::cout << "2. Venus" << std::endl;
    std::cout << "3. Earth" << std::endl;
    std::cout << "4. Earth Moon" << std::endl;
    std::cout << "5. Mars" << std::endl;
    std::cout << "6. Jupiter" << std::endl;
    std::cout << "7. Saturn" << std::endl;
    std::cout << "8. Uranus" << std::endl;
    std::cout << "9. Neptune" << std::endl;
    std::cout << "10. Pluto" << std::endl;
    std::cout << "11. Sun" << std::endl;
    std::cout << "12. All" << std::endl;
    std::cout << "13. Set Weight" << std::endl;
    std::cout << "14. Exit" << std::endl;
    std::cout << "Current Weight on " << planets[this->selectedPlanet] << ": " <<
    this->selectedWeight << std::endl;
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;
    std::cout << std::endl;
    switch (choice) {
        case 1:
            this->selectedWeight = getWeightOnMercury();
            this->selectedPlanet = 0;
            break;
        case 2:
            this->selectedWeight = getWeightOnVenus();
            this->selectedPlanet = 1;
            break;
        case 3:
            this->selectedWeight = getWeightOnEarth();
            this->selectedPlanet = 2;
            break;
        case 4:
            this->selectedWeight = getWeightOnEarthMoon();
            this->selectedPlanet = 3;
            break;
        case 5:
            this->selectedWeight = getWeightOnMars();
            this->selectedPlanet = 4;
            break;
        case 6:
            this->selectedWeight = getWeightOnJupiter();
            this->selectedPlanet = 5;
            break;
        case 7:
            this->selectedWeight = getWeightOnSaturn();
            this->selectedPlanet = 6;
            break;
        case 8:
            this->selectedWeight = getWeightOnUranus();
            this->selectedPlanet = 7;
            break;
        case 9:
            this->selectedWeight = getWeightOnNeptune();
            this->selectedPlanet = 8;
            break;
        case 10:
            this->selectedWeight = getWeightOnPluto();
            this->selectedPlanet = 9;
            break;
        case 11:
            this->selectedWeight = getWeightOnSun();
            this->selectedPlanet = 10;
            break;
        case 12:
            showAllWeights();
            std::cout << std::endl;
            break;
        case 13:
            std::cout << "Enter your w: ";
            double w;
            std::cin >> w;
            setWeight(w);
            break;
        case 14:
            exit(0);
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
    }
}

void Scale::run() {
    bool exit = false;
    std::cout << "Enter your weight in pounds: ";
    double w;
    std::cin >> w;
    this->setWeight(w);
    this->selectedWeight = this->getWeightOnEarth();
    while (!exit) {
        displayMenu();
    }
}

#endif //PHYSICSFORMULA_SCALE_H
