#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Button
{
public:
    sf::RectangleShape shape;
    sf::Text text;

    Button(sf::Font &font, std::string label, sf::Vector2f pos)
    {
        shape.setSize({240, 60});
        shape.setPosition(pos);
        shape.setFillColor(sf::Color(60, 60, 60));

        text.setFont(font);
        text.setString(label);
        text.setCharacterSize(22);
        text.setFillColor(sf::Color::White);
        text.setPosition(pos.x + 20, pos.y + 10);
    }

    bool isClicked(sf::RenderWindow &window)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2f m(sf::Mouse::getPosition(window));
            return shape.getGlobalBounds().contains(m);
        }
        return false;
    }

    void draw(sf::RenderWindow &w)
    {
        w.draw(shape);
        w.draw(text);
    }
};

class bigButton : public Button
{
public:
    bigButton(sf::Font &font, std::string label, sf::Vector2f pos) : Button(font, label, pos)
    {
        shape.setSize({300, 80});
        text.setCharacterSize(22);
        text.setPosition(pos.x + 30, pos.y + 20);
    }
};

enum class Screen
{
    MAIN,
    FLIGHTMGMNT,
    PASSENGERSERVICES,
    EMPLOYEEMGMNT
};

class LargeTextArea
{
private:
    sf::RectangleShape box;
    sf::Text text;
    sf::Font font;
    std::string content;

public:
    LargeTextArea(sf::Vector2f pos, sf::Vector2f size, unsigned int charSize = 20)
    {
        // Load font
        font.loadFromFile("arial.ttf");

        // Background box
        box.setPosition(pos);
        box.setSize(size);
        box.setFillColor(sf::Color(30, 30, 30));
        box.setOutlineColor(sf::Color::White);
        box.setOutlineThickness(2);

        // Text settings
        text.setFont(font);
        text.setCharacterSize(charSize);
        text.setFillColor(sf::Color::White);
        text.setPosition(pos.x + 5, pos.y + 5);
    }

    void setText(const std::string &t)
    {
        content = t;
        text.setString(content);
    }

    void appendLine(const std::string &t)
    {
        content += t + "\n";
        text.setString(content);
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(box);
        window.draw(text);
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(1240, 1080), "HomePage");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf") &&
        !font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf") &&
        !font.loadFromFile("/System/Library/Fonts/Arial.ttf"))
    {
        std::cout << "Error loading font! Buttons will work without text." << std::endl;
    }

    bigButton FlightMgmnttButton(font, "Flight Management", {450, 400});
    bigButton PassengerServicesButton(font, "Passenger Services", {450, 500});
    bigButton EmployeeMgmnttButton(font, "Employee Management", {450, 600});
    Button backBtn(font, "Back", {520, 900});
    LargeTextArea Flights({100, 200}, {400, 400});
    LargeTextArea Passengers({700, 200}, {400, 400});
    LargeTextArea Employees({400, 200}, {400, 400});

    Screen currentScreen = Screen::MAIN;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(30, 30, 30));

        if (currentScreen == Screen::MAIN)
        {
            sf::Text title("Airport Management System", font, 50);
            title.setPosition(275, 120);
            title.setFillColor(sf::Color::White);
            window.draw(title);

            FlightMgmnttButton.draw(window);
            PassengerServicesButton.draw(window);
            EmployeeMgmnttButton.draw(window);

            if (FlightMgmnttButton.isClicked(window))
            {
                currentScreen = Screen::FLIGHTMGMNT;
            }
            else if (PassengerServicesButton.isClicked(window))
            {
                currentScreen = Screen::PASSENGERSERVICES;
            }
            else if (EmployeeMgmnttButton.isClicked(window))
            {
                currentScreen = Screen::EMPLOYEEMGMNT;
            }
        }
        else if (currentScreen == Screen::FLIGHTMGMNT)
        {
            sf::Text title("Flight Management", font, 50);
            title.setPosition(400, 150);
            title.setFillColor(sf::Color::White);
            window.draw(title);

            Button AddFlightBtn(font, "Add Flight", {200, 720});
            Button EditFlightBtn(font, "Edit Flight", {520, 720});
            Button DeleteFlightBtn(font, "Delete Flight", {840, 720});

            AddFlightBtn.draw(window);
            EditFlightBtn.draw(window);
            DeleteFlightBtn.draw(window);
            backBtn.draw(window);

            if (backBtn.isClicked(window))
                currentScreen = Screen::MAIN;
        }
        else if (currentScreen == Screen::PASSENGERSERVICES)
        {
            sf::Text title("Passenger Services", font, 50);
            title.setPosition(400, 150);
            title.setFillColor(sf::Color::White);
            window.draw(title);

            Button AddBookingBtn(font, "Add Booking", {200, 720});
            Button Checkin(font, "Check-in", {520, 720});
            Button CancelBookingBtn(font, "Cancel Booking", {840, 720});

            AddBookingBtn.draw(window);
            Checkin.draw(window);
            CancelBookingBtn.draw(window);
            backBtn.draw(window);

            if (backBtn.isClicked(window))
                currentScreen = Screen::MAIN;
        }
        else if (currentScreen == Screen::EMPLOYEEMGMNT)
        {
            sf::Text title("Employee Management", font, 50);
            title.setPosition(350, 150);
            title.setFillColor(sf::Color::White);
            window.draw(title);

            Button ChangeAssignmentBtn(font, "Change Assignment", {200, 720});
            Button AddEmployeeBtn(font, "Add Employee", {520, 720});
            Button RemoveEmployeeBtn(font, "Remove Employee", {840, 720});

            ChangeAssignmentBtn.draw(window);
            AddEmployeeBtn.draw(window);
            RemoveEmployeeBtn.draw(window);
            backBtn.draw(window);

            if (backBtn.isClicked(window))
                currentScreen = Screen::MAIN;
        }

        window.display();
    }

    return 0;
}