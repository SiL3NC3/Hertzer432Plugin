/*
  ==============================================================================

	This file was auto-generated!

	It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class SoundTouchPlugAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
	SoundTouchPlugAudioProcessorEditor(SoundTouchPlugAudioProcessor&);
	~SoundTouchPlugAudioProcessorEditor();

	//==============================================================================
	void paint(juce::Graphics&) override;
	void resized() override;

private:
	// This reference is provided as a quick way for your editor to
	// access the processor object that created it.
	SoundTouchPlugAudioProcessor& processor;
	juce::AudioParameterBool* m_par_enabled = nullptr;
	juce::AudioParameterFloat* m_par_semitones = nullptr;
	juce::Label* m_label = nullptr;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SoundTouchPlugAudioProcessorEditor)
};
