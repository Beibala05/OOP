#pragma once

#ifndef COMPARABLE
#define COMPARABLE

#include <iostream>

struct Comparable 
{
    virtual         ~Comparable()                                                       = default;
    virtual int     getKey()                                            const           = 0;
    virtual bool    operator <  (const Comparable& other)               const           = 0;
    virtual bool    operator >  (const Comparable& other)               const           = 0;
    virtual bool    operator <= (const Comparable& other)               const           = 0;
    virtual bool    operator >= (const Comparable& other)               const           = 0;
    virtual bool    operator == (const Comparable& other)               const           = 0;
    virtual bool    operator != (const Comparable& other)               const           = 0;
};

struct A : Comparable 
{
                    A(int k);
                    ~A()                                                                = default;
    int             getKey()                                            const override;
    bool            operator <  (const Comparable& other)               const override;
    bool            operator >  (const Comparable& other)               const override;
    bool            operator <= (const Comparable& other)               const override;
    bool            operator >= (const Comparable& other)               const override;
    bool            operator == (const Comparable& other)               const override;
    bool            operator != (const Comparable& other)               const override;


    private: int  key;
};

struct B : Comparable 
{
                    B(int k);    
                    ~B();
    int             getKey()                                            const override;
    bool            operator <  (const Comparable& other)               const override;
    bool            operator >  (const Comparable& other)               const override;
    bool            operator <= (const Comparable& other)               const override;
    bool            operator >= (const Comparable& other)               const override;
    bool            operator == (const Comparable& other)               const override;
    bool            operator != (const Comparable& other)               const override;

    private: int* key;
};

#endif // COMPARABLE