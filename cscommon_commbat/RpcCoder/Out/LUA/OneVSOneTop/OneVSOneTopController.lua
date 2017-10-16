OneVSOneTopController = class("OneVSOneTopController",BaseController)

function OneVSOneTopController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=OneVSOneTopController.new(OneVSOneTopModel:getInstance())
	end 
	return self.instance
end

function OneVSOneTopController:ctor(model)
	OneVSOneTopController.super.ctor(self,model)
	
	

end

function OneVSOneTopController:modelDataUpdate( syncId, idx )

end










