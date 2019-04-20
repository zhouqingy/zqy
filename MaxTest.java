package qiumax;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class MaxTest {
	int[] arr= {-2,3,-1,6};
	@Test
	void testGetmax() {
		assertEquals(8,new Max().getmax(arr));
	}

}
