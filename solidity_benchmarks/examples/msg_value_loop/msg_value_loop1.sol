pragma solidity ^0.8.10;

contract msg_value_loop1 {
    mapping(address => uint256) public balances;

    function bad(address[] memory receivers) public payable {
        for (uint256 i=0; i < receivers.length; i++) {
            __for_loop_body_1(receivers, i);
        }
    }

    function __for_loop_body_1(address[] memory receivers, uint256 i) internal {
        balances[receivers[i]] += msg.value;
    }
}
