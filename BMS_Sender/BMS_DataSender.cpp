
#define CATCH_CONFIG_MAIN

#include "../test/catch.hpp"
#include "BMS_DataSender.h"

TEST_CASE("validate the Read operation function - readFileData_e") {
	
	StreamOpSts_t streamOpSts_s;
	char filePath[100] = "./BMS_Sender/SensorData.txt";
	
	streamOpSts_s.readSts_e   = OP_MODE_STATUS_INIT;
        streamOpSts_s.streamSts_e = OP_MODE_STATUS_INIT;
	streamOpSts_s.streamedDataLen_i = 0;
	
	streamOpSts_s = readFileData_e(filePath);
	
  	REQUIRE(streamOpSts_s.readSts_e   == OP_MODE_STATUS_SUCCESSFUL);
	REQUIRE(streamOpSts_s.streamSts_e   == OP_MODE_STATUS_SUCCESSFUL);
	REQUIRE(streamOpSts_s.streamedDataLen_i   == 50);
}

TEST_CASE("validate the Read operation function with Invalid File path - readFileData_e") {
	
	StreamOpSts_t streamOpSts_s;
	char filePath[100];
	
	streamOpSts_s.readSts_e   = OP_MODE_STATUS_INIT;
        streamOpSts_s.streamSts_e = OP_MODE_STATUS_INIT;
	streamOpSts_s.streamedDataLen_i = 0;
	
	streamOpSts_s = readFileData_e(filePath);
	
  	REQUIRE(streamOpSts_s.readSts_e   == OP_MODE_STATUS_FAILED);
	REQUIRE(streamOpSts_s.streamSts_e   == OP_MODE_STATUS_INIT);
	REQUIRE(streamOpSts_s.streamedDataLen_i   == 0);
}

TEST_CASE("validate the Send operation to console function - sendDataToConsole_e") {
	
	BmsTransOpMdSts_t streamOpSts_e;
	
        streamOpSts_e = OP_MODE_STATUS_INIT;
	
	streamOpSts_e = sendDataToConsole_e(40, 35);
	
	REQUIRE(streamOpSts_e   == OP_MODE_STATUS_SUCCESSFUL);
}

TEST_CASE("validate the case that the User has not requested the Stream operation ") {
	
	StreamOpSts_t streamOpSts_s;
	
	streamOpSts_s.readSts_e   = OP_MODE_STATUS_INIT;
        streamOpSts_s.streamSts_e = OP_MODE_STATUS_INIT;
	streamOpSts_s.streamedDataLen_i = 0;
	
	streamOpSts_s = initiateStream_e(0);
	
  	REQUIRE(streamOpSts_s.readSts_e   == OP_MODE_STATUS_INIT);
	REQUIRE(streamOpSts_s.streamSts_e   == OP_MODE_STATUS_INIT);
}

TEST_CASE("validate the case that the User has requested the Stream operation ") {
	
	StreamOpSts_t streamOpSts_s;
	
	streamOpSts_s.readSts_e   = OP_MODE_STATUS_INIT;
        streamOpSts_s.streamSts_e = OP_MODE_STATUS_INIT;
	streamOpSts_s.streamedDataLen_i = 0;
	
	streamOpSts_s = initiateStream_e(1);
	
  	REQUIRE(streamOpSts_s.readSts_e   == OP_MODE_STATUS_SUCCESSFUL);
	REQUIRE(streamOpSts_s.streamSts_e   == OP_MODE_STATUS_SUCCESSFUL);
}
