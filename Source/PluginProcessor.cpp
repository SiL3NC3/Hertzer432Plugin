/*
  ==============================================================================

	This file was auto-generated!

	It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SoundTouchPlugAudioProcessor::SoundTouchPlugAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
	: juce::AudioProcessor(BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
		.withInput("Input", juce::AudioChannelSet::stereo(), true)
#endif
		.withOutput("Output", juce::AudioChannelSet::stereo(), true)
#endif
	)
#endif
	, parameters(*this,
		nullptr,
		juce::Identifier("Hertzer432Plugin"),
		{ std::make_unique<juce::AudioParameterFloat>(
			"semitones",
			"Semitones",
			juce::NormalisableRange{-24.f,
									24.f,
									0.001f},
			1.f),
		 std::make_unique<juce::AudioParameterBool>(
			"enabled",
			"Enabled",
			true),
		 std::make_unique<juce::AudioParameterBool>(
			"locked",
			"Locked",
			true)
		}) {

	m_st = std::make_unique<soundtouch::SoundTouch>();

	semitonesParameter = parameters.getRawParameterValue("semitones");
	enabledParameter = parameters.getRawParameterValue("enabled");
	lockedParameter = parameters.getRawParameterValue("locked");

	//m_enabled = std::make_unique<bool>(true);
	//m_locked = std::make_unique<bool>(true);
	//m_semitones = std::make_unique<float>();
}

SoundTouchPlugAudioProcessor::~SoundTouchPlugAudioProcessor()
{
}

//==============================================================================
const juce::String SoundTouchPlugAudioProcessor::getName() const
{
	return JucePlugin_Name;
}

bool SoundTouchPlugAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
	return true;
#else
	return false;
#endif
}

bool SoundTouchPlugAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
	return true;
#else
	return false;
#endif
}

bool SoundTouchPlugAudioProcessor::isMidiEffect() const
{
#if JucePlugin_IsMidiEffect
	return true;
#else
	return false;
#endif
}

double SoundTouchPlugAudioProcessor::getTailLengthSeconds() const
{
	return 0.0;
}

int SoundTouchPlugAudioProcessor::getNumPrograms()
{
	return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
				// so this should be at least 1, even if you're not really implementing programs.
}

int SoundTouchPlugAudioProcessor::getCurrentProgram()
{
	return 0;
}

void SoundTouchPlugAudioProcessor::setCurrentProgram(int index)
{
}

const juce::String SoundTouchPlugAudioProcessor::getProgramName(int index)
{
	return {};
}

void SoundTouchPlugAudioProcessor::changeProgramName(int index, const juce::String& newName)
{
}

//==============================================================================
void SoundTouchPlugAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
	m_st->setChannels(2);
	m_st->setSampleRate(sampleRate);
	m_st->setPitchSemiTones(0.0);
	m_st->flush();
	m_buf.resize(2 * samplesPerBlock);
}

void SoundTouchPlugAudioProcessor::releaseResources()
{
	// When playback stops, you can use this as an opportunity to free up any
	// spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SoundTouchPlugAudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const
{
#if JucePlugin_IsMidiEffect
	ignoreUnused(layouts);
	return true;
#else
	// This is the place where you check if the layout is supported.
	// In this template code we only support mono or stereo.
	if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
		&& layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
		return false;

	// This checks if the input layout matches the output layout
#if ! JucePlugin_IsSynth
	if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
		return false;
#endif

	return true;
#endif
}
#endif

void SoundTouchPlugAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
	//if (*m_par_enabled) {
	//if (*m_enabled) {
	if (*enabledParameter) {

		juce::ScopedNoDenormals noDenormals;
		const int nch = 2;
		auto totalNumInputChannels = getTotalNumInputChannels();
		auto totalNumOutputChannels = getTotalNumOutputChannels();
		for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
			buffer.clear(i, 0, buffer.getNumSamples());

		//m_st->setPitchSemiTones(*m_par_semitones);
		//m_st->setPitchSemiTones(*m_semitones);
		m_st->setPitchSemiTones(*semitonesParameter);

		// copy input samples in interleaved format to helper buffer
		for (int i = 0; i < nch; ++i)
			for (int j = 0; j < buffer.getNumSamples(); ++j)
				m_buf[j * nch + i] = buffer.getSample(i, j);

		m_st->putSamples(m_buf.data(), buffer.getNumSamples());

		if (m_st->numSamples() >= buffer.getNumSamples()) // does SoundTouch have enough samples ready?
		{
			m_st->receiveSamples(m_buf.data(), buffer.getNumSamples());
			// copy SoundTouch output samples to split format Juce buffer
			for (int i = 0; i < nch; ++i)
				for (int j = 0; j < buffer.getNumSamples(); ++j)
					buffer.setSample(i, j, m_buf[j * nch + i]);
		}
		else
		{
			// SoundTouch didn't have enough output samples, just output silence
			buffer.clear();
		}
	}
}

//==============================================================================
bool SoundTouchPlugAudioProcessor::hasEditor() const
{
	return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* SoundTouchPlugAudioProcessor::createEditor()
{
	return new SoundTouchPlugAudioProcessorEditor(*this);
}

//==============================================================================
void SoundTouchPlugAudioProcessor::getStateInformation(juce::MemoryBlock& destData)
{
	// You should use this method to store your parameters in the memory block.
	// You could do that either as raw data, or use the XML or ValueTree classes
	// as intermediaries to make it easy to save and load complex data.

	auto state = parameters.copyState();
	std::unique_ptr<juce::XmlElement> xml(state.createXml());
	copyXmlToBinary(*xml, destData);
}

void SoundTouchPlugAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
	// You should use this method to restore your parameters from this memory block,
	// whose contents will have been created by the getStateInformation() call.

	std::unique_ptr<juce::XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));

	if (xmlState.get() != nullptr)
		if (xmlState->hasTagName(parameters.state.getType()))
			parameters.replaceState(juce::ValueTree::fromXml(*xmlState));
}

//==============================================================================
bool SoundTouchPlugAudioProcessor::getEnabled() {
	//return *m_enabled;
	return *enabledParameter;
}
void SoundTouchPlugAudioProcessor::toggleEnabled() {
	//*m_enabled = !*m_enabled;
	*enabledParameter = !*enabledParameter;
	if (*enabledParameter)
		DBG("Enabled");
	else
		DBG("Disabled");
}
bool SoundTouchPlugAudioProcessor::getLocked() {
	//return *m_locked;
	return *lockedParameter;
}
void SoundTouchPlugAudioProcessor::toggleLocked() {
	//*m_locked = !*m_locked;
	*lockedParameter = !*lockedParameter;
}
float SoundTouchPlugAudioProcessor::getPitch() {
	//return (double)*m_semitones;
	return *semitonesParameter;
}
void SoundTouchPlugAudioProcessor::setPitch(float pitch) {
	//*m_semitones = (float)pitch;
	*semitonesParameter = pitch;
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
	return new SoundTouchPlugAudioProcessor();
}
