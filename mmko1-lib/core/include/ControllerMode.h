#pragma once

/* Class for work in Bus-Controller mode */

#include <functional>

#include "TestMmko.h"

class ControllerMode
{
private:
	friend class TestMmko;
	explicit ControllerMode(TestMmko* objectMmko1, const uint16_t& rxtx);

public:
	~ControllerMode();
	/* Create command word
     * method creates 16-bit command word from fields
	 * address - address terminal device
	 * rx_tx - Reception/transmission bit(reception - 0, transmission - 1
	 * subaddress - subaddress/manage mode
	 * word_count - count of words/manage command code
	 * */
	static uint16_t PackCw(uint16_t address, uint16_t RxTx, uint16_t subAddress, uint16_t wordCount);
	/* Method for transmit message from bus-controller to terminal-device with one cmd word*/
	int32_t BusToTerminalReceive(uint16_t address, uint16_t subAddress, uint16_t wordCount, uint16_t* dataWords) const;
	/* Method for transmit message from controller to terminal-device in format F1 */
	int32_t transmitCmdF1(uint16_t address, uint16_t subAddress, uint16_t wordCount, uint16_t* dataWords);

	/* noncopyable class */
	ControllerMode(const ControllerMode&) = delete;
	ControllerMode(ControllerMode&&) = delete;
	ControllerMode& operator=(const ControllerMode&) = delete;
	ControllerMode& operator=(ControllerMode&&) = delete;

	/* Getters and Setters */
	void setRxTx(uint16_t RxTx); //set data receive/transmit bit
	[[nodiscard]] uint16_t getRxTx() const; // get data receive/transmit bit

private:
	TestMmko* testMmko;
	std::unique_ptr<unmmko1_command> commands;
	uint16_t mRxTx; /* data receive/transmit bit. It must point to action which perform terminal-device
	if 0 that means what Terminal-Device should accept Data-Word(Cmd), if 1 then transmit*/
};








