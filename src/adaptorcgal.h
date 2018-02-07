#pragma once

namespace grain
{
	class AdaptorCGAL
	{
	public:
		AdaptorCGAL();
		~AdaptorCGAL();
		int importSurface();
		int setupParameters();
		int runMeshing();
		int exportVolume();
		double getMeshingTime();
	private:
	};
}