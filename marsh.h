#ifndef MARSH_H
#define MARSH_H

#include <iostream>
#include <string>

class MARSH {
private:
    std::string startPoint;
    std::string endPoint;
    int routeNumber;

public:
    MARSH();

    void setStartPoint(const std::string& start);
    void setEndPoint(const std::string& end);
    void setRouteNumber(int number);

    std::string getStartPoint() const;
    std::string getEndPoint() const;
    int getRouteNumber() const;

    friend std::ostream& operator<<(std::ostream& out, const MARSH& marsh);
    friend std::istream& operator>>(std::istream& in, MARSH& marsh);
};

#endif
