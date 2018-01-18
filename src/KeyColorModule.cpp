#include "KeyColorModule.h"

#include "EnvelopeGenerator.h"

//----------------------------------------------------------------------------------------------------------------------

namespace cillu
{

//----------------------------------------------------------------------------------------------------------------------

KeyColorModule::KeyColorModule()
: m_eg(std::make_unique<EnvelopeGenerator>())
{

}

//----------------------------------------------------------------------------------------------------------------------

KeyColorModule::~KeyColorModule() = default;

//----------------------------------------------------------------------------------------------------------------------

void KeyColorModule::noteOn()
{
    m_eg->gate(true);
}

//----------------------------------------------------------------------------------------------------------------------

void KeyColorModule::noteOff()
{
    m_eg->gate(false);
}

//----------------------------------------------------------------------------------------------------------------------

void KeyColorModule::setHue(const float hue)
{
    m_hue = hue;
}

//----------------------------------------------------------------------------------------------------------------------

void KeyColorModule::setSaturation(const float saturation)
{
    m_saturation = saturation;
}

//----------------------------------------------------------------------------------------------------------------------

void KeyColorModule::setBrightness(const float brightness)
{
    m_eg->setSustainLevel(brightness);
    m_eg->gate(brightness != 0.);
}

//----------------------------------------------------------------------------------------------------------------------

void KeyColorModule::onTimer()
{
    m_brightness = m_eg->processValue();
}

//----------------------------------------------------------------------------------------------------------------------

void KeyColorModule::setAttack(const float value)
{
    m_eg->setAttackRate(value);
}

//----------------------------------------------------------------------------------------------------------------------

void KeyColorModule::setDecay(const float value)
{
    m_eg->setDecayRate(value);
}

//----------------------------------------------------------------------------------------------------------------------

void KeyColorModule::setRelease(const float value)
{
    m_eg->setReleaseRate(value);
}

//----------------------------------------------------------------------------------------------------------------------

} // namespace cillu