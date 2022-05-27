#include <ostream>
#include "HealthPoints.h"

HealthPoints::HealthPoints(int HP) {
    if (HP <= 0) {
        throw HealthPoints::InvalidArgument();
    } else {
        m_maxHP = HP;
        m_currentHP = HP;
    }
}

HealthPoints::HealthPoints(const HealthPoints& other):
m_maxHP(other.m_maxHP),
m_currentHP(other.m_currentHP)
{}

HealthPoints& HealthPoints::operator=(const HealthPoints& other){
    if(this == &other){
        return *this;
    }
    this->m_maxHP = other.m_maxHP;
    this->m_currentHP = other.m_currentHP;
    return *this;
}

HealthPoints& HealthPoints::operator=(const int HP){
    if(HP <= 0){
        throw HealthPoints::InvalidArgument();
    }
    else{
        this->m_maxHP = HP;
        this->m_currentHP = HP;
    }
    return *this;
}

HealthPoints& HealthPoints::operator-=(const HealthPoints& other){
    if(this->m_currentHP - other.m_currentHP <= 0){
        this->m_currentHP = 0;
        return *this;
    }
    this->m_currentHP = this->m_currentHP - other.m_currentHP;
    return *this;
}

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

HealthPoints& HealthPoints::operator+=(const HealthPoints& other){
    if(this->m_currentHP + other.m_currentHP >= this->m_maxHP){
        this->m_currentHP = this->m_maxHP;
        return *this;
    }
    this->m_currentHP = this->m_currentHP + other.m_currentHP;
    return *this;
}

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

HealthPoints& operator-(HealthPoints& lhs, const HealthPoints& rhs){
    lhs -= rhs;
    return lhs;
}

    /**
    friend HealthPoints& operator-(int lhs, HealthPoints& rhs){
        HealthPoints healthPointsLhs = lhs;
        healthPointsLhs -= rhs;
        return healthPointsLhs;
    }
    */

HealthPoints& operator+(HealthPoints& lhs, const HealthPoints& rhs){
    lhs += rhs;
    return lhs;
}

HealthPoints& operator+(int HP, HealthPoints& rhs){
    rhs += HP;
    return rhs;
}

bool operator==(const HealthPoints& lhs, const HealthPoints& rhs){
    if(lhs.m_currentHP == rhs.m_currentHP){
        return true;
    }
    return false;
}

bool operator!=(const HealthPoints& lhs, const HealthPoints& rhs){
    return !(lhs == rhs);
}

bool HealthPoints::operator<(const HealthPoints& rhs){
    if(this->m_currentHP < rhs.m_currentHP){
        return true;
    }
    return false;
}

bool operator>(const HealthPoints& lhs, const HealthPoints& rhs){
    return &rhs < &lhs;
}

bool operator<=(const HealthPoints& lhs, const HealthPoints& rhs){
    return !(&rhs < &lhs);
}

bool operator>=(const HealthPoints& lhs, const HealthPoints& rhs){
    return !(&lhs < &rhs);
}

std::ostream& operator<<(std::ostream& os, const HealthPoints HP){
    os << HP.m_currentHP << "(" << HP.m_maxHP << ")";
    return os;
}


