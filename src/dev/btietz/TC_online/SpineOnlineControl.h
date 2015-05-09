/*
 * Copyright © 2012, United States Government, as represented by the
 * Administrator of the National Aeronautics and Space Administration.
 * All rights reserved.
 * 
 * The NASA Tensegrity Robotics Toolkit (NTRT) v1 platform is licensed
 * under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0.
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific language
 * governing permissions and limitations under the License.
*/

#ifndef SPINE_ONLINE_CONTROL_H
#define SPINE_ONLINE_CONTROL_H

/**
 * @file SpineOnlineControl.h
 * @brief A controller for the template class BaseSpineModelLearning
 * @author Brian Mirletz
 * @version 1.1.0
 * $Id$
 */

#include "examples/learningSpines/BaseSpineCPGControl.h"
#include "dev/btietz/TC_goal/SpineGoalControl.h"


#include "learning/NeuroEvolution/NeuroEvolution.h"
#include "learning/Adapters/NeuroAdapter.h"
#include "learning/Configuration/configuration.h"

#include "LinearMath/btVector3.h"

class tgSpringCableActuator;
class FlemonsSpineModelGoal;

/**
 * SpineOnlineControl learns the parameters for a CPG system on a
 * spine like tensegrity structure specified as a BaseSpineModelLearning. Parameters are generated by
 * AnnealEvolution and used in the CPGEquations family of classes.
 * tgImpedanceController controllers are used for the detailed muscle control.
 * Due to the number of parameters, the learned parameters are split
 * into one config file for the nodes and another for the CPG's "edges"
 */
class SpineOnlineControl : public SpineGoalControl
{
public:

struct Config : public SpineGoalControl::Config
    {
    public:
        /**
         * The only constructor. 
         */
        Config( int ss,
        int tm,
        int om,
        int param,
        int segnum = 6,
        double ct = 0.1,
        double la = 0,
        double ha = 30,
        double lp = -1 * M_PI,
        double hp = M_PI,
        double kt = 0.0,
        double kp = 1000.0,
        double kv = 100.0,
        bool def = true,
        double cl = 10.0,
        double lf = 0.0,
        double hf = 30.0,
        double ffMin = 0.0,
        double ffMax = 0.0,
        double afMin = 0.0,
        double afMax = 0.0,
        double pfMin = 0.0,
        double pfMax = 0.0,
        double tf = 0.0,
        double feedTime = 1.0
        );
        
        const double feedbackTime;
        
    };

    SpineOnlineControl(SpineOnlineControl::Config config,	
							std::string args,
							std::string resourcePath = "",
                            std::string ec = "edgeConfig.ini",
                            std::string nc = "nodeConfig.ini",
                            std::string fc = "feedbackConfig.ini",
                            std::string gc = "goalConfig.ini");
    
    virtual ~SpineOnlineControl() {}
    
    virtual void onSetup(BaseSpineModelLearning& subject);
    
    virtual void onStep(BaseSpineModelLearning& subject, double dt);
    
    virtual void onTeardown(BaseSpineModelLearning& subject);

protected:
    
    double getGoalDist(const FlemonsSpineModelGoal* subject) const;
    
    SpineOnlineControl::Config m_config;
    
    double m_feedbackControlTime;
    
    double m_lastGoalDist;
    double m_controllerStartDist;
    
};

#endif // SPINE_FEEDBACK_CONTROL_H