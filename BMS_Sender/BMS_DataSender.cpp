
#define CATCH_CONFIG_MAIN

#include "../test/catch.hpp"
#include "BMS_DataSender.h"

TEST_CASE("validate the Read operation function - readFileData_e") {
	
	StreamOpSts_t streamOpSts_s = {0,0,0};
	streamOpSts_s = readFileData_e();
	
  	REQUIRE(streamOpSts_s.readSts_e   == OP_MODE_STATUS_SUCCESSFUL);
	REQUIRE(streamOpSts_s.streamSts_e   == OP_MODE_STATUS_SUCCESSFUL);
	REQUIRE(streamOpSts_s.streamedDataLen_i   == 50);
}

TEST_CASE("validate the case that the User has not requested the Stream operation ") {
	
	StreamOpSts_t streamOpSts_s = {0,0,0};
	streamOpSts_s = initiateStream_v(0);
	
  	REQUIRE(streamOpSts_s.readSts_e   == OP_MODE_STATUS_INIT);
	REQUIRE(streamOpSts_s.streamSts_e   == OP_MODE_STATUS_INIT);
}

TEST_CASE("validate the case that the User has requested the Stream operation ") {
	
	StreamOpSts_t streamOpSts_s = {0,0,0};
	streamOpSts_s = initiateStream_v(1);
	
  	REQUIRE(streamOpSts_s.readSts_e   == OP_MODE_STATUS_SUCCESSFUL);
	REQUIRE(streamOpSts_s.streamSts_e   == OP_MODE_STATUS_SUCCESSFUL);
}