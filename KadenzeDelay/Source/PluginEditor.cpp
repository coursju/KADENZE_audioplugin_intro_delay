/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
KadenzeDelayAudioProcessorEditor::KadenzeDelayAudioProcessorEditor (KadenzeDelayAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);


    auto& params = processor.getParameters();

    //mDryWetSlider
    AudioParameterFloat* dryWetParameter = (AudioParameterFloat*)params.getUnchecked(0);
    mDryWetSlider.setBounds(0, 0, 100, 100);
    mDryWetSlider.setSliderStyle(Slider::SliderStyle::RotaryHorizontalDrag);
    mDryWetSlider.setRange(dryWetParameter->range.start, dryWetParameter->range.end);
    mDryWetSlider.setValue(*dryWetParameter);
    mDryWetSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    addAndMakeVisible(mDryWetSlider);

    mDryWetSlider.onValueChange = [this, dryWetParameter] {*dryWetParameter = mDryWetSlider.getValue(); };
    mDryWetSlider.onDragStart = [dryWetParameter] {dryWetParameter->beginChangeGesture(); };
    mDryWetSlider.onDragEnd = [dryWetParameter] {dryWetParameter->endChangeGesture(); };

    ////mFeedbackSlider
    //AudioParameterFloat* feedbackParameter = (AudioParameterFloat*)params.getUnchecked(1);
    //mFeedbackSlider.setBounds(100, 0, 100, 100);
    //mFeedbackSlider.setSliderStyle(Slider::SliderStyle::RotaryHorizontalDrag);
    //mFeedbackSlider.setRange(feedbackParameter->range.start, feedbackParameter->range.end);
    //mFeedbackSlider.setValue(*feedbackParameter);
    //mFeedbackSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    //addAndMakeVisible(mFeedbackSlider);

    //mFeedbackSlider.onValueChange = [this, feedbackParameter] {*feedbackParameter = mFeedbackSlider.getValue(); };
    //mFeedbackSlider.onDragStart = [feedbackParameter] {feedbackParameter->beginChangeGesture(); };
    //mFeedbackSlider.onDragEnd = [feedbackParameter] {feedbackParameter->endChangeGesture(); };

    ////mDelayTimeSlider
    //AudioParameterFloat* DelayTimeParameter = (AudioParameterFloat*)params.getUnchecked(2);
    //mDelayTimeSlider.setBounds(200, 0, 100, 100);
    //mDelayTimeSlider.setSliderStyle(Slider::SliderStyle::RotaryHorizontalDrag);
    //mDelayTimeSlider.setRange(DelayTimeParameter->range.start, DelayTimeParameter->range.end);
    //mDelayTimeSlider.setValue(*DelayTimeParameter);
    //mDelayTimeSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    //addAndMakeVisible(mDelayTimeSlider);

    //mDelayTimeSlider.onValueChange = [this, DelayTimeParameter] {*DelayTimeParameter = mDelayTimeSlider.getValue(); };
    //mDelayTimeSlider.onDragStart = [DelayTimeParameter] {DelayTimeParameter->beginChangeGesture(); };
    //mDelayTimeSlider.onDragEnd = [DelayTimeParameter] {DelayTimeParameter->endChangeGesture(); };



}

KadenzeDelayAudioProcessorEditor::~KadenzeDelayAudioProcessorEditor()
{
}

//==============================================================================
void KadenzeDelayAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void KadenzeDelayAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
