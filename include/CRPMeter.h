#ifndef CRPMETER_H
#define	CRPMETER_H

#include <stdint.h>
#include <boost/thread.hpp>

#include "CI2C.h"

class CRPMeter  : CSensor
{
    public:
        CRPMeter(CI2C * pI2C, uint8_t iAddress);
        virtual ~CRPMeter();
        
        void start();
        void stop();
        void kill();
        void run();
        
    private:
        boost::recursive_mutex  m_RPMeterMutex;
        boost::thread           m_RPMeterThread;
        bool                    m_bStop;
        CI2C *                  m_pI2C;
        uint8_t                 m_iAddress;

};

#endif	/* RPMETER_H */
