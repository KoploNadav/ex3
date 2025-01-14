#ifndef HEALTHPOINTS_H
#define HEALTHPOINTS_H

#include <ostream>

class HealthPoints{
    int m_maxHP;
    int m_currentHP;

    static const int DEFAULT_MAX_HP = 100;

public:

    class InvalidArgument{};

    /**
     *@brief Construct a new HealthPoint, default hp is 100.
     *
     * @param HP Amount of HP to assign.
     */
    HealthPoints(int HP = DEFAULT_MAX_HP);

    /**
     *@brief Copy C'tor
     *
     * @param other Other HealthPoints to copy from.
     */
    HealthPoints(const HealthPoints& other);

    /**
     * @brief D'tor
     */
    ~HealthPoints() = default;

    /**
     * @brief = operator with another HealthPoints object.
     *
     * @param other Other HealthPoints to copy from.
     * @return
     */

    HealthPoints& operator=(const HealthPoints& other);

    /**
     * @brief = operator with an int.
     *
     * @param HP Amount of HP to assign.
     * @return
     */

    HealthPoints& operator=(const int HP);

    /**
     * @brief - operator with another HealthPoints object.
     *
     * @param other Other HealthPoints to subtract from.
     * @return
     */

    HealthPoints& operator-=(const HealthPoints& other);

    /**
     * @brief - operator with an int
     *
     * @param HP Amount of HP to assign.
     * @return
     */

    /*
     * HealthPoints& operator-=(int HP){
        if(this->m_currentHP - HP <= 0){
            this->m_currentHP = 0;
            return *this;
        }
        this->m_currentHP = this->m_currentHP - HP;
        return *this;
    }
     */

    /**
     * @brief += operator with another HealthPoints object.
     *
     * @param other Other HealthPoints to add from.
     * @return
     */

    HealthPoints& operator+=(const HealthPoints& other);

    /**
     * @brief += operator with an int
     *
     * @param HP Amount of HP to assign.
     * @return
     */

    /*
     * HealthPoints& operator+=(int HP) {
        if (this->m_currentHP - HP >= this->m_maxHP) {
            this->m_currentHP = this->m_maxHP;
            return *this;
        }
        this->m_currentHP = this->m_currentHP - HP;
        return *this;
    }
     */

    /**
     *@brief - operator with two HealthPoints objects.
     *
     * @param lhs Left HealthPoints
     * @param rhs Right HealthPoints.
     * @return
     */

    friend HealthPoints& operator-(HealthPoints& lhs, const HealthPoints& rhs);

    /**
     *@brief - operator with two HealthPoints objects.
     *
     * @param lhs Left HealthPoints
     * @param rhs Right HealthPoints.
     * @return
     */

    /**
    friend HealthPoints& operator-(int lhs, HealthPoints& rhs){
        HealthPoints healthPointsLhs = lhs;
        healthPointsLhs -= rhs;
        return healthPointsLhs;
    }
    */

    /**
     *@brief + operator with two HealthPoints objects.
     *
     * @param lhs Left HealthPoints
     * @param rhs Right HealthPoints.
     * @return
     */

    friend HealthPoints& operator+(HealthPoints& lhs, const HealthPoints& rhs);

    /**
     *@brief + operator with an int and a HealthPoints object.
     *
     * @param HP hp to add.
     * @param rhs Right HealthPoints.
     * @return
     */

    friend HealthPoints& operator+(int HP, HealthPoints& rhs);

    friend bool operator==(const HealthPoints& lhs, const HealthPoints& rhs);

    friend bool operator!=(const HealthPoints& lhs, const HealthPoints& rhs);

    bool operator<(const HealthPoints& rhs);

    friend bool operator>(const HealthPoints& lhs, const HealthPoints& rhs);

    friend bool operator<=(const HealthPoints& lhs, const HealthPoints& rhs);

    friend bool operator>=(const HealthPoints& lhs, const HealthPoints& rhs);

    friend std::ostream& operator<<(std::ostream& os, const HealthPoints HP);

};


#endif //HEALTHPOINTS_H
