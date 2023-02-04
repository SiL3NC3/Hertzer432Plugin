/*
  ==============================================================================

	This file was auto-generated!

	It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SoundTouch/SoundTouch.h"

//==============================================================================
/**
*/
class SoundTouchPlugAudioProcessor : public juce::AudioProcessor
{
public:
	//==============================================================================
	SoundTouchPlugAudioProcessor();
	~SoundTouchPlugAudioProcessor();

	//==============================================================================
	void prepareToPlay(double sampleRate, int samplesPerBlock) override;
	void releaseResources() override;

#ifndef JucePlugin_PreferredChannelConfigurations
	bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
#endif

	void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

	//==============================================================================
	juce::AudioProcessorEditor* createEditor() override;
	bool hasEditor() const override;

	//==============================================================================
	const juce::String getName() const override;

	bool acceptsMidi() const override;
	bool producesMidi() const override;
	bool isMidiEffect() const override;
	double getTailLengthSeconds() const override;

	//==============================================================================
	int getNumPrograms() override;
	int getCurrentProgram() override;
	void setCurrentProgram(int index) override;
	const juce::String getProgramName(int index) override;
	void changeProgramName(int index, const juce::String& newName) override;

	//==============================================================================
	void getStateInformation(juce::MemoryBlock& destData) override;
	void setStateInformation(const void* data, int sizeInBytes) override;

	//==============================================================================
	bool getEnabled();
	void toggleEnabled();
	bool getLocked();
	void toggleLocked();
	double getPitch();
	void setPitch(double pitch);

private:
	std::unique_ptr<soundtouch::SoundTouch> m_st;
	std::unique_ptr<bool> m_enabled;
	std::unique_ptr<bool> m_locked;
	std::unique_ptr<float> m_semitones;

	std::vector<float> m_buf; // helper buffer to get samples into/from SoundTouch
	juce::AudioParameterBool* m_par_enabled = nullptr;
	juce::AudioParameterBool* m_par_locked = nullptr;
	juce::AudioParameterFloat* m_par_semitones = nullptr;
	juce::Label* m_label = nullptr;
	juce::GenericAudioProcessorEditor* editor = nullptr;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SoundTouchPlugAudioProcessor)
};
